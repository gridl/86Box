/*
 * 86Box	A hypervisor and IBM PC system emulator that specializes in
 *		running old operating systems and software designed for IBM
 *		PC systems and compatibles from 1981 through fairly recent
 *		system designs based on the PCI bus.
 *
 *		This file is part of the 86Box distribution.
 *
 *		Implementation of the CD-ROM null interface for unmounted
 *		guest CD-ROM drives.
 *
 * Version:	@(#)cdrom_null.c	1.0.2	2017/09/03
 *
 * Authors:	Sarah Walker, <http://pcem-emulator.co.uk/>
 *		Miran Grca, <mgrca8@gmail.com>
 *		Copyright 2008-2016 Sarah Walker.
 *		Copyright 2016-2017 Miran Grca.
 */
#include "../ibm.h"
#include "../cdrom/cdrom.h"
#include "../cdrom/cdrom_ioctl.h"


static CDROM ioctl_cdrom;


static int ioctl_ready(uint8_t id)
{
        return 0;
}

/* Always return 0, the contents of a null CD-ROM drive never change. */
static int ioctl_medium_changed(uint8_t id)
{
        return 0;
}

static uint8_t ioctl_getcurrentsubchannel(uint8_t id, uint8_t *b, int msf)
{
        return 0x13;
}

void ioctl_reset(uint8_t id)
{

}

int ioctl_open(uint8_t id, char d)
{
        return 0;
}

static void ioctl_eject(uint8_t id)
{
}

static void ioctl_load(uint8_t id)
{
}

static int ioctl_readsector_raw(uint8_t id, uint8_t *buffer, int sector, int ismsf, int cdrom_sector_type, int cdrom_sector_flags, int *len)
{
	*len = 0;
	return 0;
}

static int ioctl_readtoc(uint8_t id, unsigned char *b, unsigned char starttrack, int msf, int maxlen, int single)
{
        return 0;
}

static int ioctl_readtoc_session(uint8_t id, unsigned char *b, int msf, int maxlen)
{
		return 0;
}

static int ioctl_readtoc_raw(uint8_t id, unsigned char *b, int maxlen)
{
		return 0;
}

static uint32_t ioctl_size(uint8_t id)
{
        return 0;
}

static int ioctl_status(uint8_t id)
{
	return CD_STATUS_EMPTY;
}

void cdrom_ioctl_reset(uint8_t id)
{
}

void cdrom_set_ioctl_handler(uint8_t id);

int cdrom_ioctl_open(uint8_t id, char d)
{
	cdrom_set_ioctl_handler(id);
        return 0;
}

void ioctl_close(uint8_t id)
{
}

static void ioctl_exit(uint8_t id)
{
}

static int ioctl_is_track_audio(uint8_t id, uint32_t pos, int ismsf)
{
	return 0;
}

static int ioctl_pass_through(uint8_t id, uint8_t *in_cdb, uint8_t *b, uint32_t *len)
{
	return 0;
}

static int ioctl_media_type_id(uint8_t id)
{
	return 0x70;
}

void cdrom_set_ioctl_handler(uint8_t id)
{
	cdrom_drives[id].handler = &ioctl_cdrom;
	cdrom_drives[id].host_drive = 0;
	memset(cdrom_image[id].image_path, 0, sizeof(cdrom_image[id].image_path));
}

static CDROM ioctl_cdrom =
{
	ioctl_ready,
	ioctl_medium_changed,
	ioctl_media_type_id,
	NULL,
	NULL,
        ioctl_readtoc,
        ioctl_readtoc_session,
	ioctl_readtoc_raw,
        ioctl_getcurrentsubchannel,
        ioctl_pass_through,
	ioctl_readsector_raw,
        NULL,
        ioctl_load,
        ioctl_eject,
        NULL,
        NULL,
        ioctl_size,
	ioctl_status,
	ioctl_is_track_audio,
        NULL,
        ioctl_exit
};
