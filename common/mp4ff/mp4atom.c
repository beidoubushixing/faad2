/*
** FAAD2 - Freeware Advanced Audio (AAC) Decoder including SBR decoding
** Copyright (C) 2003 M. Bakker, Ahead Software AG, http://www.nero.com
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
**
** Any non-GPL usage of this software or parts of this software is strictly
** forbidden.
**
** Commercial non-GPL licensing of this software is possible.
** For more info contact Ahead Software through Mpeg4AAClicense@nero.com.
**
** $Id: mp4atom.c,v 1.5 2003/11/25 13:16:09 menno Exp $
**/

#include <stdlib.h>
#include "mp4ffint.h"


/* parse atom header size */
static int32_t mp4ff_atom_get_size(const int8_t *data)
{
    uint32_t result;
    uint32_t a, b, c, d;

    a = (uint8_t)data[0];
    b = (uint8_t)data[1];
    c = (uint8_t)data[2];
    d = (uint8_t)data[3];

    result = (a<<24) | (b<<16) | (c<<8) | d;
    if (result > 0 && result < 8) result = 8;

    return (int32_t)result;
}

/* comnapre 2 atom names, returns 1 for equal, 0 for unequal */
static int32_t mp4ff_atom_compare(const int8_t a1, const int8_t b1, const int8_t c1, const int8_t d1,
                                  const int8_t a2, const int8_t b2, const int8_t c2, const int8_t d2)
{
    if (a1 == a2 && b1 == b2 && c1 == c2 && d1 == d2)
        return 1;
    else
        return 0;
}

static uint8_t mp4ff_atom_name_to_type(const int8_t a, const int8_t b,
                                       const int8_t c, const int8_t d)
{
    if (a == 'm')
    {
        if (mp4ff_atom_compare(a,b,c,d, 'm','o','o','v'))
            return ATOM_MOOV;
        else if (mp4ff_atom_compare(a,b,c,d, 'm','i','n','f'))
            return ATOM_MINF;
        else if (mp4ff_atom_compare(a,b,c,d, 'm','d','i','a'))
            return ATOM_MDIA;
        else if (mp4ff_atom_compare(a,b,c,d, 'm','d','a','t'))
            return ATOM_MDAT;
        else if (mp4ff_atom_compare(a,b,c,d, 'm','d','h','d'))
            return ATOM_MDHD;
        else if (mp4ff_atom_compare(a,b,c,d, 'm','v','h','d'))
            return ATOM_MVHD;
        else if (mp4ff_atom_compare(a,b,c,d, 'm','p','4','a'))
            return ATOM_MP4A;
        else if (mp4ff_atom_compare(a,b,c,d, 'm','p','4','v'))
            return ATOM_MP4V;
        else if (mp4ff_atom_compare(a,b,c,d, 'm','p','4','s'))
            return ATOM_MP4S;
        else if (mp4ff_atom_compare(a,b,c,d, 'm','e','t','a'))
            return ATOM_META;
    } else if (a == 't') {
        if (mp4ff_atom_compare(a,b,c,d, 't','r','a','k'))
            return ATOM_TRAK;
        else if (mp4ff_atom_compare(a,b,c,d, 't','k','h','d'))
            return ATOM_TKHD;
        else if (mp4ff_atom_compare(a,b,c,d, 't','r','e','f'))
            return ATOM_TREF;
        else if (mp4ff_atom_compare(a,b,c,d, 't','r','k','n'))
            return ATOM_TRACK;
        else if (mp4ff_atom_compare(a,b,c,d, 't','m','p','o'))
            return ATOM_TEMPO;
    } else if (a == 's') {
        if (mp4ff_atom_compare(a,b,c,d, 's','t','b','l'))
            return ATOM_STBL;
        else if (mp4ff_atom_compare(a,b,c,d, 's','m','h','d'))
            return ATOM_SMHD;
        else if (mp4ff_atom_compare(a,b,c,d, 's','t','s','d'))
            return ATOM_STSD;
        else if (mp4ff_atom_compare(a,b,c,d, 's','t','t','s'))
            return ATOM_STTS;
        else if (mp4ff_atom_compare(a,b,c,d, 's','t','c','o'))
            return ATOM_STCO;
        else if (mp4ff_atom_compare(a,b,c,d, 's','t','s','c'))
            return ATOM_STSC;
        else if (mp4ff_atom_compare(a,b,c,d, 's','t','s','z'))
            return ATOM_STSZ;
        else if (mp4ff_atom_compare(a,b,c,d, 's','t','z','2'))
            return ATOM_STZ2;
        else if (mp4ff_atom_compare(a,b,c,d, 's','k','i','p'))
            return ATOM_SKIP;
    } else if (a == '�') {
        if (mp4ff_atom_compare(a,b,c,d, '�','n','a','m'))
            return ATOM_TITLE;
        else if (mp4ff_atom_compare(a,b,c,d, '�','A','R','T'))
            return ATOM_ARTIST;
        else if (mp4ff_atom_compare(a,b,c,d, '�','w','r','t'))
            return ATOM_WRITER;
        else if (mp4ff_atom_compare(a,b,c,d, '�','a','l','b'))
            return ATOM_ALBUM;
        else if (mp4ff_atom_compare(a,b,c,d, '�','d','a','y'))
            return ATOM_DATE;
        else if (mp4ff_atom_compare(a,b,c,d, '�','t','o','o'))
            return ATOM_TOOL;
        else if (mp4ff_atom_compare(a,b,c,d, '�','c','m','t'))
            return ATOM_COMMENT;
        else if (mp4ff_atom_compare(a,b,c,d, '�','g','e','n'))
            return ATOM_GENRE1;
    }

    if (mp4ff_atom_compare(a,b,c,d, 'e','d','t','s'))
        return ATOM_EDTS;
    else if (mp4ff_atom_compare(a,b,c,d, 'e','s','d','s'))
        return ATOM_ESDS;
    else if (mp4ff_atom_compare(a,b,c,d, 'f','t','y','p'))
        return ATOM_FTYP;
    else if (mp4ff_atom_compare(a,b,c,d, 'f','r','e','e'))
        return ATOM_FREE;
    else if (mp4ff_atom_compare(a,b,c,d, 'h','m','h','d'))
        return ATOM_HMHD;
    else if (mp4ff_atom_compare(a,b,c,d, 'v','m','h','d'))
        return ATOM_VMHD;
    else if (mp4ff_atom_compare(a,b,c,d, 'u','d','t','a'))
        return ATOM_UDTA;
    else if (mp4ff_atom_compare(a,b,c,d, 'i','l','s','t'))
        return ATOM_ILST;
    else if (mp4ff_atom_compare(a,b,c,d, 'n','a','m','e'))
        return ATOM_NAME;
    else if (mp4ff_atom_compare(a,b,c,d, 'd','a','t','a'))
        return ATOM_DATA;
    else if (mp4ff_atom_compare(a,b,c,d, 'd','i','s','k'))
        return ATOM_DISC;
    else if (mp4ff_atom_compare(a,b,c,d, 'g','n','r','e'))
        return ATOM_GENRE2;
    else if (mp4ff_atom_compare(a,b,c,d, 'c','p','i','l'))
        return ATOM_COMPILATION;
    else
        return ATOM_UNKNOWN;
}

/* read atom header, return atom size, atom size is with header included */
int32_t mp4ff_atom_read_header(mp4ff_t *f, uint8_t *atom_type)
{
    int32_t size;
    int32_t ret;
    int8_t atom_header[8];

    ret = mp4ff_read_data(f, atom_header, 8);
    if (ret != 8)
        return 0;

    size = mp4ff_atom_get_size(atom_header);

    //printf("%c%c%c%c\n", atom_header[4], atom_header[5], atom_header[6], atom_header[7]);

    *atom_type = mp4ff_atom_name_to_type(atom_header[4], atom_header[5], atom_header[6], atom_header[7]);

    return size;
}

static int32_t mp4ff_read_stsz(mp4ff_t *f)
{
    mp4ff_read_char(f); /* version */
    mp4ff_read_int24(f); /* flags */
    f->track[f->total_tracks - 1]->stsz_sample_size = mp4ff_read_int32(f);
    f->track[f->total_tracks - 1]->stsz_sample_count = mp4ff_read_int32(f);

    if (f->track[f->total_tracks - 1]->stsz_sample_size == 0)
    {
        int32_t i;
        f->track[f->total_tracks - 1]->stsz_table =
            (int32_t*)malloc(f->track[f->total_tracks - 1]->stsz_sample_count*sizeof(int32_t));

        for (i = 0; i < f->track[f->total_tracks - 1]->stsz_sample_count; i++)
        {
            f->track[f->total_tracks - 1]->stsz_table[i] = mp4ff_read_int32(f);
        }
    }

    return 0;
}

static int32_t mp4ff_read_esds(mp4ff_t *f)
{
    uint8_t tag;

    mp4ff_read_char(f); /* version */
    mp4ff_read_int24(f); /* flags */

    /* get and verify ES_DescrTag */
    tag = mp4ff_read_char(f);
    if (tag == 0x03)
    {
        /* read length */
        if (mp4ff_read_mp4_descr_length(f) < 5 + 15)
        {
            return 1;
        }
        /* skip 3 bytes */
        mp4ff_read_int24(f);
    } else {
        /* skip 2 bytes */
        mp4ff_read_int16(f);
    }

    /* get and verify DecoderConfigDescrTab */
    if (mp4ff_read_char(f) != 0x04)
    {
        return 1;
    }

    /* read length */
    if (mp4ff_read_mp4_descr_length(f) < 15)
    {
        return 1;
    }

    /* skip 13 bytes */
    mp4ff_read_int32(f);
    mp4ff_read_int32(f);
    mp4ff_read_int32(f);
    mp4ff_read_char(f);

    /* get and verify DecSpecificInfoTag */
    if (mp4ff_read_char(f) != 0x05)
    {
        return 1;
    }

    /* read length */
    f->track[f->total_tracks - 1]->decoderConfigLen = mp4ff_read_mp4_descr_length(f); 

    if (f->track[f->total_tracks - 1]->decoderConfig)
        free(f->track[f->total_tracks - 1]->decoderConfig);
    f->track[f->total_tracks - 1]->decoderConfig = malloc(f->track[f->total_tracks - 1]->decoderConfigLen);
    if (f->track[f->total_tracks - 1]->decoderConfig)
    {
        mp4ff_read_data(f, f->track[f->total_tracks - 1]->decoderConfig, f->track[f->total_tracks - 1]->decoderConfigLen);
    } else {
        f->track[f->total_tracks - 1]->decoderConfigLen = 0;
    }

    /* will skip the remainder of the atom */
    return 0;
}

static int32_t mp4ff_read_mp4a(mp4ff_t *f)
{
    int32_t i, size;
    uint8_t atom_type = 0;

    for (i = 0; i < 6; i++)
    {
        mp4ff_read_char(f); /* reserved */
    }
    /* data_reference_index */ mp4ff_read_int16(f);

    mp4ff_read_int32(f); /* reserved */
    mp4ff_read_int32(f); /* reserved */

    f->track[f->total_tracks - 1]->channelCount = mp4ff_read_int16(f);
    f->track[f->total_tracks - 1]->sampleSize = mp4ff_read_int16(f);

    mp4ff_read_int16(f);
    mp4ff_read_int16(f);

    f->track[f->total_tracks - 1]->sampleRate = mp4ff_read_int16(f);

    mp4ff_read_int16(f);

    size = mp4ff_atom_read_header(f, &atom_type);
    if (atom_type == ATOM_ESDS)
    {
        mp4ff_read_esds(f);
    }

    return 0;
}

static int32_t mp4ff_read_stsd(mp4ff_t *f)
{
    int32_t i;

    mp4ff_read_char(f); /* version */
    mp4ff_read_int24(f); /* flags */

    f->track[f->total_tracks - 1]->stsd_entry_count = mp4ff_read_int32(f);

    for (i = 0; i < f->track[f->total_tracks - 1]->stsd_entry_count; i++)
    {
        int32_t skip = mp4ff_position(f);
        int32_t size;
        uint8_t atom_type = 0;
        size = mp4ff_atom_read_header(f, &atom_type);
        skip += size;

        if (atom_type == ATOM_MP4A)
        {
            f->track[f->total_tracks - 1]->type = TRACK_AUDIO;
            mp4ff_read_mp4a(f);
        } else if (atom_type == ATOM_MP4V) {
            f->track[f->total_tracks - 1]->type = TRACK_VIDEO;
        } else if (atom_type == ATOM_MP4S) {
            f->track[f->total_tracks - 1]->type = TRACK_SYSTEM;
        } else {
            f->track[f->total_tracks - 1]->type = TRACK_UNKNOWN;
        }

        mp4ff_set_position(f, skip);
    }

    return 0;
}

static int32_t mp4ff_read_stsc(mp4ff_t *f)
{
    int32_t i;

    mp4ff_read_char(f); /* version */ 
    mp4ff_read_int24(f); /* flags */ 
    f->track[f->total_tracks - 1]->stsc_entry_count = mp4ff_read_int32(f);

    f->track[f->total_tracks - 1]->stsc_first_chunk =
        (int32_t*)malloc(f->track[f->total_tracks - 1]->stsc_entry_count*sizeof(int32_t));
    f->track[f->total_tracks - 1]->stsc_samples_per_chunk =
        (int32_t*)malloc(f->track[f->total_tracks - 1]->stsc_entry_count*sizeof(int32_t));
    f->track[f->total_tracks - 1]->stsc_sample_desc_index =
        (int32_t*)malloc(f->track[f->total_tracks - 1]->stsc_entry_count*sizeof(int32_t));

    for (i = 0; i < f->track[f->total_tracks - 1]->stsc_entry_count; i++)
    {
        f->track[f->total_tracks - 1]->stsc_first_chunk[i] = mp4ff_read_int32(f);
        f->track[f->total_tracks - 1]->stsc_samples_per_chunk[i] = mp4ff_read_int32(f);
        f->track[f->total_tracks - 1]->stsc_sample_desc_index[i] = mp4ff_read_int32(f);
    }

    return 0;
}

static int32_t mp4ff_read_stco(mp4ff_t *f)
{
    int32_t i;

    mp4ff_read_char(f); /* version */
    mp4ff_read_int24(f); /* flags */
    f->track[f->total_tracks - 1]->stco_entry_count = mp4ff_read_int32(f);

    f->track[f->total_tracks - 1]->stco_chunk_offset =
        (int32_t*)malloc(f->track[f->total_tracks - 1]->stco_entry_count*sizeof(int32_t));

    for (i = 0; i < f->track[f->total_tracks - 1]->stco_entry_count; i++)
    {
        f->track[f->total_tracks - 1]->stco_chunk_offset[i] = mp4ff_read_int32(f);
    }

    return 0;
}

static int32_t mp4ff_read_stts(mp4ff_t *f)
{
    int32_t i;

    mp4ff_read_char(f); /* version */
    mp4ff_read_int24(f); /* flags */
    f->track[f->total_tracks - 1]->stts_entry_count = mp4ff_read_int32(f);

    f->track[f->total_tracks - 1]->stts_sample_count = (int32_t*)malloc(f->track[f->total_tracks - 1]->stts_entry_count * sizeof(int32_t));
    f->track[f->total_tracks - 1]->stts_sample_delta = (int32_t*)malloc(f->track[f->total_tracks - 1]->stts_entry_count * sizeof(int32_t));

    for (i = 0; i < f->track[f->total_tracks - 1]->stts_entry_count; i++)
    {
        f->track[f->total_tracks - 1]->stts_sample_count[i] = mp4ff_read_int32(f);
        f->track[f->total_tracks - 1]->stts_sample_delta[i] = mp4ff_read_int32(f);
    }

    return 0;
}

static int32_t mp4ff_read_mvhd(mp4ff_t *f)
{
    int32_t i;

    mp4ff_read_char(f); /* version */
    mp4ff_read_int24(f); /* flags */
    /* creation_time */ mp4ff_read_int32(f);
    /* modification_time */ mp4ff_read_int32(f);
    f->time_scale = mp4ff_read_int32(f);
    f->duration = mp4ff_read_int32(f);
    /* preferred_rate */ mp4ff_read_int32(f); /*mp4ff_read_fixed32(f);*/
    /* preferred_volume */ mp4ff_read_int16(f); /*mp4ff_read_fixed16(f);*/
    for (i = 0; i < 10; i++)
    {
        /* reserved */ mp4ff_read_char(f);
    }
    for (i = 0; i < 9; i++)
    {
        mp4ff_read_int32(f); /* matrix */
    }
    /* preview_time */ mp4ff_read_int32(f);
    /* preview_duration */ mp4ff_read_int32(f);
    /* poster_time */ mp4ff_read_int32(f);
    /* selection_time */ mp4ff_read_int32(f);
    /* selection_duration */ mp4ff_read_int32(f);
    /* current_time */ mp4ff_read_int32(f);
    /* next_track_id */ mp4ff_read_int32(f);

    return 0;
}

#ifdef USE_TAGGING
static int32_t mp4ff_read_meta(mp4ff_t *f, const int32_t size)
{
    int32_t subsize, sumsize = 0;
    uint8_t atom_type;

    mp4ff_read_char(f); /* version */
    mp4ff_read_int24(f); /* flags */

    while (sumsize < (size-12))
    {
        subsize = mp4ff_atom_read_header(f, &atom_type);
        if (atom_type == ATOM_ILST)
        {
            mp4ff_parse_metadata(f, subsize);
        } else {
            mp4ff_set_position(f, mp4ff_position(f)+subsize-8);
        }
        sumsize += subsize;
    }

    return 0;
}
#endif

int32_t mp4ff_atom_read(mp4ff_t *f, const int32_t size, const uint8_t atom_type)
{
    if (atom_type == ATOM_STSZ)
    {
        /* sample size box */
        mp4ff_read_stsz(f);
    } else if (atom_type == ATOM_STTS) {
        /* time to sample box */
        mp4ff_read_stts(f);
    } else if (atom_type == ATOM_STSC) {
        /* sample to chunk box */
        mp4ff_read_stsc(f);
    } else if (atom_type == ATOM_STCO) {
        /* chunk offset box */
        mp4ff_read_stco(f);
    } else if (atom_type == ATOM_STSD) {
        /* sample description box */
        mp4ff_read_stsd(f);
    } else if (atom_type == ATOM_MVHD) {
        /* movie header box */
        mp4ff_read_mvhd(f);
#ifdef USE_TAGGING
    } else if (atom_type == ATOM_META) {
        /* iTunes Metadata box */
        mp4ff_read_meta(f, size);
#endif
    } else {
        /* skip this atom: not needed for reading */
        mp4ff_set_position(f, mp4ff_position(f)+size-8);
    }

    return 0;
}
