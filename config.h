/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 6;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 0;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "CozetteVector:size=12" };
static const char dmenufont[]       = "CozetteVector:size=12";
static const char col_gray1[]       = "#222222"; // Root window color
static const char col_gray2[]       = "#222222"; // Window border color
static const char col_gray3[]       = "#71aaaa"; // Active tab text color
static const char col_gray4[]       = "#71eeee"; // Tab text color
static const char col_cyan[]        = "#222222"; // Top bar color
static const char col_selected[]    = "#71aaaa"; // Seleted window border color
// Nobuntu blue: #61cccc
// #71ffff
// #71aaaa
// #7eeeee
// #222222
// Nimbrain teal: #00ff91
static const char *colors[][4]      = {
	/*               fg         bg         border      select*/
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2, col_selected },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan, col_selected },
};

/* tagging */
static const char *tags[] = { "G", "O", "R", "E", "S", "H", "I", "T", "!" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[#]",      tile },    /* first entry is default */
	{ "/\\/",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-i", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "alacritty", NULL };
static const char *browser[] = { "firefox" };
static const char *discord[] = { "discord" };
static const char *screenshot[] = { "spectacle", "-fr", NULL};
static const char *emotica[] = { "emotica.sh" };
static const char *emoji[] = { "emoji.sh" };
static const char *setlang[] = { "setlang.sh" };
static const char *logout[] = { "logout.sh" };
static const char *volUp[] = { "audioUP.sh" };
static const char *volDown[] = { "audioDOWN.sh" };
static const char *translation[] = { "translate.sh" };
static const char *unicode[] = { "unicode.sh" };
static const char *gajim[] = { "gajim" };
static const char *time[] = { "time.sh" };
static const char *word[] = { "word.sh" };
static const char *vidya[] = { "vidya.sh" };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,	                XK_Print,  spawn,	   {.v = screenshot } },
	{ MODKEY,			XK_b,	   spawn,	   {.v = browser } },
	{ MODKEY|ShiftMask,		XK_b,	   spawn,	   {.v = discord } },	
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
        { MODKEY,                       XK_e,      spawn,          {.v = emoji} },
	{ MODKEY|ShiftMask,             XK_e,      spawn,          {.v = emotica } },
        { MODKEY|ShiftMask,             XK_F1,     spawn,          {.v = setlang } },
	{ MODKEY,                       XK_period, spawn,          {.v = volUp} },
	{ MODKEY,                       XK_comma,  spawn,          {.v = volDown} },
	{ MODKEY|ShiftMask,             XK_t,      spawn,          {.v = translation } },
	{ MODKEY,                       XK_y,      spawn,          {.v = time } },
	{ MODKEY,                       XK_w,      spawn,          {.v = word } },
	{ MODKEY,                       XK_u,      spawn,          {.v = unicode } },
	{ MODKEY,                       XK_g,      spawn,          {.v = gajim } },
	{ MODKEY|ShiftMask,             XK_v,      spawn,          {.v = vidya } },
	{ MODKEY,                       XK_v,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      spawn,          {.v = logout } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
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
