.PHONY: all build test clean

BUILDDIR=./build

all: build

build:
	[ -d $(BUILDDIR) ] || meson $(BUILDDIR)
	ninja -C$(BUILDDIR)

test:
	[ -d $(BUILDDIR) ] || meson $(BUILDDIR)
	cd $(BUILDDIR) && meson test --verbose

clean:
	rm -r $(BUILDDIR)
