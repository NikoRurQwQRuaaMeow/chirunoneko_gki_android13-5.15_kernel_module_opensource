# SPDX-License-Identifier: GPL-2.0

obj-$(CONFIG_MI_LAUNCH_BOOST)	+= iorap2.o

iorap2-y			:= launch_boost.o
iorap2-y			+= launch_boost_com.o
iorap2-y			+= launch_boost_collect.o
iorap2-y			+= launch_boost_preread.o
iorap2-y			+= launch_boost_clear.o
iorap2-y			+= launch_boost_flush.o
iorap2-y			+= launch_boost_dbg.o
iorap2-y			+= pte_hot_preread.o

ccflags-y			+= -DDEFAULT_SYMBOL_NAMESPACE=VFS_internal_I_am_really_a_filesystem_and_am_NOT_a_driver
