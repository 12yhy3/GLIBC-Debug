# Library for profiling, built with the same options as libc
ifeq (,$(filter stage1 stage2,$(DEB_BUILD_PROFILES)))
ifeq (,$(filter i386 s390x,$(DEB_HOST_ARCH))) # LP: #1898049
  GLIBC_PASSES += prof
  DEB_ARCH_REGULAR_PACKAGES += $(libc)-prof
  prof_configure_target = $(libc_configure_target)
  prof_extra_cflags = $(libc_extra_cflags) -fno-omit-frame-pointer
  prof_extra_config_options = $(libc_extra_config_options)
  prof_mvec = $(libc_mvec)
  prof_slibdir = /lib/$(libc)-prof/$(DEB_HOST_MULTIARCH)/
endif
endif
