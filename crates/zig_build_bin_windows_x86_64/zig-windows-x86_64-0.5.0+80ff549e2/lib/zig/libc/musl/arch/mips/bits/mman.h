#undef MAP_ANON
#define MAP_ANON       0x800
#undef MAP_NORESERVE
#define MAP_NORESERVE  0x0400
#undef MAP_GROWSDOWN
#define MAP_GROWSDOWN  0x1000
#undef MAP_DENYWRITE
#define MAP_DENYWRITE  0x2000
#undef MAP_EXECUTABLE
#define MAP_EXECUTABLE 0x4000
#undef MAP_LOCKED
#define MAP_LOCKED     0x8000
#undef MAP_POPULATE
#define MAP_POPULATE   0x10000
#undef MAP_NONBLOCK
#define MAP_NONBLOCK   0x20000
#undef MAP_STACK
#define MAP_STACK      0x40000
#undef MAP_HUGETLB
#define MAP_HUGETLB    0x80000
#undef MAP_SYNC

#if defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#undef MADV_SOFT_OFFLINE
#endif
