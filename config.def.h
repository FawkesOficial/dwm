/* See LICENSE file for copyright and license details. */

#define BROWSER "firefox"
#define FILE_EXPLORER "nautilus"
#define TERMINAL "st"

/* appearance */
static const unsigned int borderpx  = 5;        /* border pixel of windows */
static const unsigned int gappx     = 10;        /* gaps between windows */
static const unsigned int snap      = 24;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;    /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 0;     /* 0 means no systray */
static const int showbar            = 1;     /* 0 means no bar */
static const int topbar             = 1;     /* 0 means bottom bar */
static const int vertpad            = 10;       /* vertical padding of bar */
static const int sidepad            = 10;       /* horizontal padding of bar */
static const char *fonts[]          = {
    "Noto Sans Mono:style=Regular:size=10:antialias=true:autohint:true",
    "Font Awesome 6 Free:style=Solid:size=10:antialias=true:autohint:true",
    "Font Awesome 6 Brands:size=10:antialias=true:autohint:true",
    "NotoSansMono Nerd Font Mono:size=16:antialias=true:autohint:true"
};
static const char dmenufont[]       = "NotoSansMono Nerd Font:size=12:antialias=true:autohint:true";
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#005577";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "辶", "", "" };

static const Rule rules[] = {
    /* xprop(1):
     *  WM_CLASS(STRING) = instance, class
     *  WM_NAME(STRING) = title
     */
    /* class                instance    title         tags mask    switchtotag    isfloating    monitor */
    { "Gimp",               NULL,       NULL,         0,           0,             0,            -1 },
    { "discord",            NULL,       "Discord",    1 << 3,      1,             0,             1 },
    { "obs",                "obs",      "OBS ",       1 << 6,      1,             0,             1 },
    { NULL,                 "cmus",     "cmus",       1 << 7,      1,             0,             1 },
    { "Spotify",            NULL,       NULL,         1 << 7,      1,             0,             1 },
    { "org.gnome.Nautilus", NULL,       NULL,         1 << 2,      1,             0,            -1 },
    { "code-oss",           NULL,       NULL,         1 << 4,      1,             0,            -1 },
    { "Signal",             NULL,       NULL,         1 << 3,      1,             0,            -1 },
    { "mpv",                NULL,       "lofi",       1 << 7,      0,             1,             1 },
    { NULL,  "jellyfinmediaplayer",     NULL,         1 << 6,      1,             0,            -1 },
    { "MultiMC",            NULL,       NULL,         1 << 5,      1,             0,             0 },
    { "obsidian",           "obsidian", "Obsidian",   1 << 2,      1,             0,             1 },
    { "jetbrains-idea",     NULL,       NULL,         1 << 4,      1,             0,             0 },
    { "jetbrains-pycharm",  NULL,       NULL,         1 << 4,      1,             0,             0 },
    { "yazi",               NULL,       NULL,         1 << 2,      1,             0,            -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
//static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL }; // Default colorscheme
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selbordercolor, NULL };
static const char *termcmd[]  = { "st", NULL };

/* Power Menu*/
static const char *powermenu[] = { "dwm-powermenu", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selbordercolor, NULL };

/* Task Manager */
static const char *taskmanager[] = { "dwm-taskmanager", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selbordercolor, NULL };

/* Emoji and Unicode Character Picker*/
static const char *dmenuunicode[] = { "dwm-dmenuunicode", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selbordercolor, NULL };

/* Clipboard Manager */
static const char *clipmanager[] = { "clipmenu", NULL };

/* Email (FN + F10) */
static const char *emailcmd[] = { BROWSER, "https://mail.proton.me/u/0/inbox", NULL};

/* Calculator (FN + F12)*/
static const char *calculator[] = { "st", "-e", "calc", NULL };

#include <X11/XF86keysym.h>

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ Mod4Mask,                     XK_v,      spawn,          {.v = clipmanager } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          {.v = powermenu } },
	{ ControlMask|ShiftMask,        XK_Escape, spawn,          {.v = taskmanager } },
	{ Mod4Mask,                     XK_u,      spawn,          {.v = dmenuunicode } },
	{ 0,                            XK_Print,  spawn,          SHCMD("maim -s -u | xclip -selection clipboard -t image/png -i") },
	{ MODKEY,                       XK_w,      spawn,          {.v = (const char*[]){ BROWSER, NULL } } },
	{ MODKEY,                       XK_e,      spawn,          {.v = (const char*[]){ "st", "-c", "yazi", "-e", "yazi", NULL } } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_plus,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	{ MODKEY,                       XK_F5,     xrdb,           {.v = NULL } },
	/* Media Keys */
	{ 0, XF86XK_AudioLowerVolume,   spawn,                     SHCMD("pamixer -d 5") },
	{ 0, XF86XK_AudioRaiseVolume,   spawn,                     SHCMD("pamixer -i 5") },
	{ 0, XF86XK_AudioMute,          spawn,                     SHCMD("pamixer -t") },
	{ 0, XF86XK_AudioStop,          spawn,                     SHCMD("cmus-remote -C player-stop") },
	{ 0, XF86XK_AudioPrev,          spawn,                     SHCMD("cmus-remote -C player-prev") },
	{ 0, XF86XK_AudioPlay,          spawn,                     SHCMD("cmus-remote -C player-pause") },
	{ 0, XF86XK_AudioNext,          spawn,                     SHCMD("cmus-remote -C player-next") },
	/* Other Special Keys*/
	{ 0, XF86XK_Mail,               spawn,                     {.v = emailcmd } },
	{ 0, XF86XK_HomePage,           spawn,                     {.v = dmenucmd } },
	{ 0, XF86XK_Calculator,         spawn,                     {.v = calculator } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

