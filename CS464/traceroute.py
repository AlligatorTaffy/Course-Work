"""
AlligatorTaffy
Programming Assignment - Python3 Traceroute
April 21, 2019


##### NOTES #####

Python3 adds a ton of overhead that a standard traceroute from a shell does not have.
With that said, the time to calculate the RTT per packet is slightly inflated as well
as might be off due to not being able to get a timestamp off the sent packet.  I have
a local timestamp that I capture moments before sending the packet, then I subtract
that from the timestamp from the received packet.  Either way, it simulates the time
the packet takes and is within the scope of the assignment.

I had to do timeout error checking or it could be in an infinite loop attempting to
CTRL-C out of the timeout waiting for a packet to come back that had been dropped by
routers that block ICMP echo packets.

#################
"""
# Imported External Modules
from scapy.all import *
import time


# Function Definitions
def Traceroute(host):
	trace = True
	address = IP(dst=host)
	address.ttl = 1
	packet = ICMP()
	timeout = 0
	while trace:
		if timeout == 30:
			print("Traceroute aborted: Too many failed attempts (30 packets)")
			break
		send = time.time()
		reply = sr1(address/packet, verbose=False, timeout = 15)
		if reply == None:
			print(address.ttl, "Packet Timeout - ICMP may be disabled at router")
			address.ttl += 1
			timeout += 1
			continue
		if address.ttl == 1:
			receive = reply.time
			rtt = (receive - send) * 1000
			print("1 hop --", reply.src, "     RTT =", rtt, "ms")
			address.ttl += 1
			timeout = 0
			continue
		if reply.type == 0:
			receive = reply.time
			rtt = (receive - send) * 1000
			print(address.ttl, "hops --", reply.src, "     RTT =", rtt, "ms", "--", host)
			break
		else:
			receive = reply.time
			rtt = (receive - send) * 1000
			print(address.ttl, "hops --", reply.src, "     RTT =", rtt, "ms")
			address.ttl += 1
			timeout = 0


# Main Script
print("\nLet's Start a Traceroute!")
loop = True
while loop:
	hostname = input("What is the hostname to your destination?\n")
	Traceroute(hostname)
	while loop:
		quit = input("\nWould you like to do another traceroute? (y/n) ")
		if quit == "y":
			break
		elif quit == "n":
			exit()
		else:
			print("Invalid Response, try again.")
