#include "mem/cache/tags/fifo.hh"

#include "debug/CacheRepl.hh"
#include "mem/cache/base.hh"

FIFO::FIFO(const Params *p)
    : BaseSetAssoc(p)
{
}

CacheBlk*
FIFO::accessBlock(Addr addr, bool is_secure, Cycles &lat)
{
    /*
     * Write your implementation here.
     */
}

CacheBlk*
FIFO::findVictim(Addr addr)
{
    /*
     * Write your implementation here.
     */
}

void
FIFO::insertBlock(PacketPtr pkt, BlkType *blk)
{
    BaseSetAssoc::insertBlock(pkt, blk);

    int set = extractSet(pkt->getAddr());
    sets[set].moveToHead(blk);
}

void
FIFO::invalidate(CacheBlk *blk)
{
    BaseSetAssoc::invalidate(blk);

    // should be evicted before valid blocks
    int set = blk->set;
    sets[set].moveToTail(blk);
}

FIFO*
FIFOParams::create()
{
    return new FIFO(this);
}
