# My build of dwm

![dwm logo](dwm.png)

---

## Added features

+ xrdb/pywal/Xresources compatibility. Just load Xresources with `xrdb path/to/Xresources` or generate a colorscheme using pywal. Then hit `Mod+F5` to apply the changes.
+ Systray(disabled due to it not conforming to the floating bar layout).
+ Status bar shows up in  all monitors.
+ Switch to the configured tag when a window opens, then switch back when it closes.
+ Fullscreen Applications
+ Printscreen select area and copy to clipboard. Similar to Lightshot on Windows
+ Media Keys: Vol-Up, Vol-Dow, Mute. **For cmus**: Stop, Prev, Play/Pause, Next.
+ Autostart: dwm will run `~/.config/dwm/autostart.sh` at start. [See more info below](#autostart). 
+ Power Menu (Requires `dmenu`)
+ Task Manager/Task Killer (Requires `dmenu`)
+ Emoji/Font Awesome and other Unicode characters Menu: Select a character and it will be automatically copied to the clipboard (Requires `dmenu`)
+ Clipboard Manager. Similar to `Win+v` on Windows10. (Requires `clipmenu`. You can find it on Github or in the AUR)

---

## Bindings

+ Default MODKEY: `alt`
+ Launch Terminal: `mod+return`
+ dmenu: `mod+p`
+ Clipboard Manager: `win+v`
+ Power Menu: `mod+shift+s`
+ Task Manager: `ctrl+shift+esc`
+ Emoji/Unicode Menu: `win+u`
+ Printscreen Select: `PrtSc` (Just hit the PrintScreen key on your keyboard)
+ Open Browser: `mod+w` (Browser defined in **config.h**)
+ Open File Explorer: `mod+e` (File Explorer defined in **config.h**)
+ Toggle Fullscreen: `mod+shift+f`
+ Reload Colorscheme: `mod+F5`
+ Increase/Decrease/Reset Gaps: `mod++`, `mod+-`, `mod+=`

---

## Autostart

1. Create the folder `~/.config/dwm` and the file `~/.config/dwm/autostart.sh`.
2. Add execution permissions to `~/.config/dwm/autostart.sh`
```shell
chmod +x ~/.config/dwm/autostart.sh
```
3. Edit the file and make it run whatever you want

>Example `~/.config/dwm/autostart.sh`:
```shell
discord &
obsidian &
sleep 2; st -n htop -e htop &                         (example of a terminal app)
```

---

## Applied patches

+ [autostart](https://dwm.suckless.org/patches/autostart/) (modified to look for `autostart.sh` in `~/.config/dwm` instead of `~/.dwm`)
+ [actualfullscreen](https://dwm.suckless.org/patches/actualfullscreen/)
+ [alwayscenter](https://dwm.suckless.org/patches/alwayscenter/)
+ [statusallmons](https://dwm.suckless.org/patches/statusallmons/)
+ [switchtotag](https://dwm.suckless.org/patches/switchtotag/) (slightly modified to support multi-monitor setups. See [this commit](https://github.com/FawkesOficial/dwm/commit/d4c21b5921a1734773a6d59d8b61868d1b2ab495) for more info)
+ [systray](https://dwm.suckless.org/patches/systray/)
+ [xrdb](https://dwm.suckless.org/patches/xrdb/)
+ [fullgaps](https://dwm.suckless.org/patches/fullgaps/)
+ [barpadding](https://dwm.suckless.org/patches/fullgaps/)

---

## Contact

- [Github](https://github.com/FawkesOficial)
- [Twitter](https://twitter.com/FawkesOficial)
