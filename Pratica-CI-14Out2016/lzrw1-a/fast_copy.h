/******************************************************************************/
/*                                  fast_copy.h                               */
/******************************************************************************/

void fast_copy(void *src_adr, void *dst_adr, unsigned long src_len);
/* This function copies a block of memory very quickly.                       */
/* The exact speed depends on the relative alignment of the blocks of memory. */
/* PRE  : 0<=src_len<=(2^32)-1 .                                              */
/* PRE  : Source and destination blocks must not overlap.                     */
/* POST : MEM[dst_adr,dst_adr+src_len-1]=MEM[src_adr,src_adr+src_len-1].      */
/* POST : MEM[dst_adr,dst_adr+src_len-1] is the only memory changed.          */

#define fast_copy(src,dst,n) memcpy(dst,src,n)
/******************************************************************************/
/*                               End of fast_copy.h                           */
/******************************************************************************/
