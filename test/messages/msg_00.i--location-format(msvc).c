/* Generated by re2c */

{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':	goto yy3;
	default:	goto yy2;
	}
yy2:
yy3:
	++YYCURSOR;
	{}
}

messages/msg_00.i--location-format(msvc).re(3,2): warning: control flow is undefined for strings that match '[\x0-\x60\x62-\xFF]', use default rule '*' [-Wundefined-control-flow]