#include <linux/if_ether.h>
#include <string.h>
#include <stdint.h>

struct eth_hdr
{
	unsigned char dmac[6];
	unsigned char smac[6];
	uint16_t ethertype;
	unsigned char payload[];
} __attribute__((packed));

if (tun_read(buf, BUFLEN) < 0) {
	print_error("ERR: Read from tun_fd: %s\n", strerror(erno));
}

struct eth_hdr *hdr = init_eth_hdr(buf);

handle_frame(&netdev, hdr);

struct arp_hdr
{
	uint16_t hwtype;
	uint16_t protype;
	unsigned char hwsize;
	unsigned char prosize;
	uint16_t opcode;
	unsigned char data[];
}__attribute__((packed));

struct arp_hdr
{
	uint16_t hwtype;
	uint16_t protype;
	unsigned char hwsize;
	unsigned char prosize;
	uint16_t opcode;
	unsigned char data[];
}__attribute__((packed));

struct arp_ipv4
{
	unsigned char smac[6];
	uint32_t sip;
	unsigned char dmac[6];
	uint32_t dip;
}__attribute__((packed));


int tun_alloc(char *dev)
{
	struct ifreq ifr;
	int fd, err;

	if ((fd = open("/dev/net/tap", 0_RDWR)) < 0) {
		print_error("Cannot open TUN/TAP dev");
		exit(1);
	}
	CLEAR(ifr);

	ifr.ifr_flags = IFF_TAP | IFF_NO_PI;
	if (*dev) {
		strncpy(ifr.ifr_name, dev, IFNAMSIZ);
	}

	if (err = ioctl(fd, TUNSETIFF, (void*) &ifr) < 0) {
		print_error("ERR: Could not ioctl tun: %s\n", sterror(erno));
		close(fd);
		return err;
	}

	strcpy(dev, ifr.ifr_name);
	return fd;
}
