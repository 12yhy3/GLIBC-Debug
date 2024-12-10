GLIBC_GIT = https://sourceware.org/git/glibc.git
GLIBC_BRANCH = release/$(DEB_VERSION_UPSTREAM)/master
GLIBC_TAG = glibc-$(DEB_VERSION_UPSTREAM)
GLIBC_CHECKOUT = glibc-checkout
DEB_ORIG_UNCOMPRESSED = ../glibc_$(DEB_VERSION_UPSTREAM).orig.tar
DEB_ORIG = $(DEB_ORIG_UNCOMPRESSED).xz
GIT_UPDATES_DIFF = debian/patches/git-updates.diff

# Note: 'git archive' doesn't support https remotes, so 'git clone' is used as a first step

get-orig-source: $(DEB_ORIG)
$(DEB_ORIG):
	dh_testdir
	git clone --bare $(GLIBC_GIT) $(GLIBC_CHECKOUT)
	git archive -v --format=tar --prefix=$(GLIBC_TAG)/ --remote=$(GLIBC_CHECKOUT) -o $(DEB_ORIG_UNCOMPRESSED) $(GLIBC_TAG)
	rm -rf $(GLIBC_CHECKOUT)
	tar --delete $(GLIBC_TAG)/manual -f $(DEB_ORIG_UNCOMPRESSED)
	xz $(DEB_ORIG_UNCOMPRESSED)

update-from-upstream:
	dh_testdir
	git fetch origin
	h=$$(git log -n 1 --format=%H origin/$(GLIBC_BRANCH)); \
	echo "GIT update of $(GLIBC_GIT)/$(GLIBC_BRANCH) from $(GLIBC_TAG) to $$h" > $(GIT_UPDATES_DIFF)
	echo "" >> $(GIT_UPDATES_DIFF)
	git diff --no-renames $(GLIBC_TAG) origin/$(GLIBC_BRANCH) >> $(GIT_UPDATES_DIFF)

make-new-snapshot:
	git fetch origin
	d=$$(git describe origin/master); \
	v=$$(echo $$d | sed 's/-/_/'); \
	dv=$$(echo $$v | sed 's/.*_//')-0ubuntu1; \
	git archive --prefix=$$d/ origin/master | xz -9evk > ../$$v.orig.tar.xz; \
	dch -v $$dv ''
