
ACLOCAL_AMFLAGS = -I m4
AUTOMAKE_OPTIONS = subdir-objects

# the main library
lib_LTLIBRARIES = \
    memspace/libmemspace/libmemspace.la

memspace_libmemspace_libmemspace_la_SOURCES = \
    memspace/libmemspace/libmemspace.c \
    memspace/libmemspace/libmemspace.h

memspace_libmemspace_libmemspace_la_includedir = $(includedir)/libmemspace
memspace_libmemspace_libmemspace_la_include_HEADERS = \
    memspace/libmemspace/libmemspace.h

memspace_libmemspace_libmemspace_la_LIBADD = -lrt
memspace_libmemspace_libmemspace_la_LDFLAGS = -version-info 0:0:0

## pkgconfig integration
pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libmemspace.pc

# test programs
bin_PROGRAMS = \
    memspace/maintenance/destroy\
    memspace/producerconsumer/producer \
    memspace/producerconsumer/consumer

memspace_maintenance_destroy_SOURCES = \
    memspace/maintenance/destroy.c
memspace_maintenance_destroy_LDADD = $(lib_LTLIBRARIES)
memspace_maintenance_destroy_CFLAGS = -I $(top_srcdir)/memspace

memspace_producerconsumer_producer_SOURCES = \
    memspace/producerconsumer/producer.c
memspace_producerconsumer_producer_LDADD = $(lib_LTLIBRARIES)
memspace_producerconsumer_producer_CFLAGS = -I $(top_srcdir)/memspace

memspace_producerconsumer_consumer_SOURCES = \
    memspace/producerconsumer/consumer.c
memspace_producerconsumer_consumer_LDADD = $(lib_LTLIBRARIES)
memspace_producerconsumer_consumer_CFLAGS = -I $(top_srcdir)/memspace
