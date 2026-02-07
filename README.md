# Hello World GTK

This is a simple app i made to learn C and GTK

And could be very useful to check a GTK installation and theme on a UNIX-like system.

## How to build 

### Default Build (No permanent installation)

```shell
# 1.
meson setup builddir
# 2.
cd buiddir
# 3.
meson compile
# 4.
./hello-world-gtk
```

### Arch Linux Package (full native installation)

``` shell
# 1. 
makepkg -p -i 'pkg/arch/PKGBUILD' 
```

#### -git and .release are avaiable but not ready for use yet.

### Flatpak 

```shell
# 1. (to make surr that flathub is installed)
flatpak remote-add --user --if-not-exists flathub https://dl.flathub.org/repo/flathub.flatpakrepo
# 2. 
flatpak-builder .flatpak/ --verbose --force-clean --ccache --install-deps-from=flathub --install --user 'pkg/flatpak/io.github.xgui4.hello.world.gtk.yml'
```