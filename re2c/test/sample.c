/* Generated by re2c */
#line 1 "sample.re"

#line 5 "<stdout>"
{
	YYCTYPE yych;

	if ((YYLIMIT - YYCURSOR) < 6) YYFILL(6);
	yych = *YYCURSOR;
	switch (yych) {
	case '0':	goto yy5;
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy7;
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy4;
	case 'p':	goto yy2;
	default:	goto yy8;
	}
yy2:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case 'r':	goto yy19;
	default:	goto yy18;
	}
yy3:
#line 3 "sample.re"
	{return ID;}
#line 59 "<stdout>"
yy4:
	yych = *++YYCURSOR;
	goto yy18;
yy5:
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'x':	goto yy12;
	default:	goto yy11;
	}
yy6:
#line 4 "sample.re"
	{return DEC;}
#line 72 "<stdout>"
yy7:
	yych = *++YYCURSOR;
	goto yy11;
yy8:
	++YYCURSOR;
#line 6 "sample.re"
	{return ERR;}
#line 80 "<stdout>"
yy10:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy11:
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy10;
	default:	goto yy6;
	}
yy12:
	yych = *++YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':	goto yy14;
	default:	goto yy13;
	}
yy13:
	YYCURSOR = YYMARKER;
	goto yy6;
yy14:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':	goto yy14;
	default:	goto yy16;
	}
yy16:
#line 5 "sample.re"
	{return HEX;}
#line 149 "<stdout>"
yy17:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy18:
	switch (yych) {
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy17;
	default:	goto yy3;
	}
yy19:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'i':	goto yy20;
	default:	goto yy18;
	}
yy20:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'n':	goto yy21;
	default:	goto yy18;
	}
yy21:
	yych = *++YYCURSOR;
	switch (yych) {
	case 't':	goto yy22;
	default:	goto yy18;
	}
yy22:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy17;
	default:	goto yy23;
	}
yy23:
#line 2 "sample.re"
	{return PRINT;}
#line 236 "<stdout>"
}
#line 7 "sample.re"

