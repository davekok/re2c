/* Generated by re2c 0.13.4.dev on Sat Mar 22 17:57:39 2008 */
/* $Id$ */
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <stdarg.h>
#include "scanner.h"
#include "parser.h"
#include "y.tab.h"
#include "globals.h"
#include "dfa.h"

extern YYSTYPE yylval;

#ifndef MAX
#define MAX(a,b) (((a)>(b))?(a):(b))
#endif

#define	BSIZE		8192
#define	YYCTYPE		unsigned char
#define	YYCURSOR	cursor
#define	YYLIMIT		lim
#define	YYMARKER	ptr
#define	YYCTXMARKER ctx
#define	YYFILL(n)	{cursor = fill(cursor, n);}

#define	RETURN(i)	{cur = cursor; return i;}

namespace re2c
{

Scanner::Scanner(std::istream& i, std::ostream& o)
	: in(i)
	, out(o)
	, bot(NULL), tok(NULL), ptr(NULL), cur(NULL), pos(NULL), lim(NULL)
	, top(NULL), eof(NULL), ctx(NULL), tchar(0), tline(0), cline(1), iscfg(0)
	, in_parse(false)
{
	;
}

char *Scanner::fill(char *cursor, uint need)
{
	if(!eof)
	{
		uint cnt = tok - bot;
		if(cnt)
		{
			memmove(bot, tok, top - tok);
			tok = bot;
			ptr -= cnt;
			cursor -= cnt;
			pos -= cnt;
			lim -= cnt;
		}
		need = MAX(need, BSIZE);
		if(static_cast<uint>(top - lim) < need)
		{
			char *buf = new char[(lim - bot) + need];
			if (!buf)
			{
				fatal("Out of memory");
			}
			memcpy(buf, tok, lim - tok);
			tok = buf;
			ptr = &buf[ptr - bot];
			cursor = &buf[cursor - bot];
			pos = &buf[pos - bot];
			lim = &buf[lim - bot];
			top = &lim[need];
			delete [] bot;
			bot = buf;
		}
		in.read(lim, need);
		if((cnt = in.gcount()) != need)
		{
			eof = &lim[cnt];
			*eof++ = '\0';
		}
		lim += cnt;
	}
	return cursor;
}



Scanner::ParseMode Scanner::echo()
{
	char *cursor = cur;
	bool ignore_eoc = false;
	int  ignore_cnt = 0;

	if (eof && cursor == eof) // Catch EOF
	{
		return Stop;
	}

	tok = cursor;
echo:

{
	YYCTYPE yych;
	unsigned int yyaccept = 0;

	if ((YYLIMIT - YYCURSOR) < 16) YYFILL(16);
	yych = *YYCURSOR;
	if (yych <= ')') {
		if (yych <= 0x00) goto yy7;
		if (yych == '\n') goto yy5;
		goto yy9;
	} else {
		if (yych <= '*') goto yy4;
		if (yych != '/') goto yy9;
	}
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == '*') goto yy16;
yy3:
	{
					goto echo;
				}
yy4:
	yych = *++YYCURSOR;
	if (yych == '/') goto yy10;
	goto yy3;
yy5:
	++YYCURSOR;
	{
					if (ignore_eoc)
					{
						ignore_cnt++;
					}
					else if (!DFlag)
					{
						out.write((const char*)(tok), (const char*)(cursor) - (const char*)(tok));
					}
					tok = pos = cursor;
					cline++;
					goto echo;
				}
yy7:
	++YYCURSOR;
	{
					if (!ignore_eoc && !DFlag)
					{
						out.write((const char*)(tok), (const char*)(cursor) - (const char*)(tok) - 1);
						// -1 so we don't write out the \0
					}
					if(cursor == eof)
					{
						RETURN(Stop);
					}
				}
yy9:
	yych = *++YYCURSOR;
	goto yy3;
yy10:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == '\n') goto yy14;
	if (yych == '\r') goto yy12;
yy11:
	{
					if (ignore_eoc)
					{
						if (ignore_cnt)
						{
							out << "\n" << sourceFileInfo;
						}
						ignore_eoc = false;
						ignore_cnt = 0;
					}
					else if (!DFlag)
					{
						out.write((const char*)(tok), (const char*)(cursor) - (const char*)(tok));
					}
					tok = pos = cursor;
					goto echo;
				}
yy12:
	yych = *++YYCURSOR;
	if (yych == '\n') goto yy14;
yy13:
	YYCURSOR = YYMARKER;
	if (yyaccept <= 0) {
		goto yy3;
	} else {
		goto yy11;
	}
yy14:
	++YYCURSOR;
	{
					cline++;
					if (ignore_eoc)
					{
						if (ignore_cnt)
						{
							out << sourceFileInfo;
						}
						ignore_eoc = false;
						ignore_cnt = 0;
					}
					else if (!DFlag)
					{
						out.write((const char*)(tok), (const char*)(cursor) - (const char*)(tok));
					}
					tok = pos = cursor;
					goto echo;
				}
yy16:
	yych = *++YYCURSOR;
	if (yych != '!') goto yy13;
	yych = *++YYCURSOR;
	switch (yych) {
	case 'g':	goto yy20;
	case 'i':	goto yy19;
	case 'm':	goto yy21;
	case 'r':	goto yy22;
	case 't':	goto yy18;
	default:	goto yy13;
	}
yy18:
	yych = *++YYCURSOR;
	if (yych == 'y') goto yy69;
	goto yy13;
yy19:
	yych = *++YYCURSOR;
	if (yych == 'g') goto yy58;
	goto yy13;
yy20:
	yych = *++YYCURSOR;
	if (yych == 'e') goto yy45;
	goto yy13;
yy21:
	yych = *++YYCURSOR;
	if (yych == 'a') goto yy37;
	goto yy13;
yy22:
	yych = *++YYCURSOR;
	if (yych != 'e') goto yy13;
	yych = *++YYCURSOR;
	if (yych == '2') goto yy25;
	if (yych != 'p') goto yy13;
	yych = *++YYCURSOR;
	if (yych == 'e') goto yy28;
	goto yy13;
yy25:
	yych = *++YYCURSOR;
	if (yych != 'c') goto yy13;
	++YYCURSOR;
	{
					if (rFlag)
					{
						mapCodeName.clear();
					}
					if (bUsedYYMaxFill && bSinglePass)
					{
						fatal("found scanner block after YYMAXFILL declaration");
					}
					if (!DFlag)
					{
						out.write((const char*)(tok), (const char*)(&cursor[-7]) - (const char*)(tok));
					}
					tok = cursor;
					RETURN(Parse);
				}
yy28:
	yych = *++YYCURSOR;
	if (yych != 'a') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 't') goto yy13;
	yych = *++YYCURSOR;
	if (yych != ':') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 'r') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 'e') goto yy13;
	yych = *++YYCURSOR;
	if (yych != '2') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 'c') goto yy13;
	++YYCURSOR;
	{
					if (!rFlag)
					{
						fatal("Cannot reuse scanner definition without -r flag");
					}
					next_label = 0;
					next_fill_index = 0;
					bWroteGetState = false;
					bWroteCondCheck = false;
					mapCodeName.clear();
					if (bUsedYYMaxFill && bSinglePass)
					{
						fatal("found scanner block after YYMAXFILL declaration");
					}
					if (!DFlag)
					{
						out.write((const char*)(tok), (const char*)(&cursor[-14]) - (const char*)(tok));
					}
					tok = cursor;
					RETURN(Reuse);
				}
yy37:
	yych = *++YYCURSOR;
	if (yych != 'x') goto yy13;
	yych = *++YYCURSOR;
	if (yych != ':') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 'r') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 'e') goto yy13;
	yych = *++YYCURSOR;
	if (yych != '2') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 'c') goto yy13;
	++YYCURSOR;
	{
					if (bUsedYYMaxFill)
					{
						fatal("cannot generate YYMAXFILL twice");
					}
					if (!DFlag)
					{
						out << "#define YYMAXFILL " << maxFill << std::endl;
					}
					tok = pos = cursor;
					ignore_eoc = true;
					bUsedYYMaxFill = true;
					goto echo;
				}
yy45:
	yych = *++YYCURSOR;
	if (yych != 't') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 's') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 't') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 'a') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 't') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 'e') goto yy13;
	yych = *++YYCURSOR;
	if (yych != ':') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 'r') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 'e') goto yy13;
	yych = *++YYCURSOR;
	if (yych != '2') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 'c') goto yy13;
	++YYCURSOR;
	{
					tok = pos = cursor;
					genGetStateGoto(out, topIndent, 0);
					ignore_eoc = true;
					goto echo;
				}
yy58:
	yych = *++YYCURSOR;
	if (yych != 'n') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 'o') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 'r') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 'e') goto yy13;
	yych = *++YYCURSOR;
	if (yych != ':') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 'r') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 'e') goto yy13;
	yych = *++YYCURSOR;
	if (yych != '2') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 'c') goto yy13;
	++YYCURSOR;
	{
					tok = pos = cursor;
					ignore_eoc = true;
					goto echo;
				}
yy69:
	yych = *++YYCURSOR;
	if (yych != 'p') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 'e') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 's') goto yy13;
	yych = *++YYCURSOR;
	if (yych != ':') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 'r') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 'e') goto yy13;
	yych = *++YYCURSOR;
	if (yych != '2') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 'c') goto yy13;
	++YYCURSOR;
	{
					if (bSinglePass)
					{
						fatal("cannot generate types inline in single pass mode");
					}
					tok = pos = cursor;
					ignore_eoc = true;
					if (bLastPass && !DFlag)
					{
						out << outputFileInfo;
						out << "\n";
						out << typesInline;
						out << "\n";
						out << sourceFileInfo;
					}
					goto echo;
				}
}

}

int Scanner::scan()
{
	char *cursor = cur;
	uint depth;

scan:
	tchar = cursor - pos;
	tline = cline;
	tok = cursor;
	if (iscfg == 1)
	{
		goto config;
	}
	else if (iscfg == 2)
	{
		goto value;
	}

{
	YYCTYPE yych;
	unsigned int yyaccept = 0;
	static const unsigned char yybm[] = {
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 116,   0, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		116, 112,  48, 112, 112, 112, 112,  80, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 112, 112, 112, 112, 112, 112, 
		112, 120, 120, 120, 120, 120, 120, 120, 
		120, 120, 120, 120, 120, 120, 120, 120, 
		120, 120, 120, 120, 120, 120, 120, 120, 
		120, 120, 120, 112,   0,  96, 112, 120, 
		112, 120, 120, 120, 120, 120, 120, 120, 
		120, 120, 120, 120, 120, 120, 120, 120, 
		120, 120, 120, 120, 120, 120, 120, 120, 
		120, 120, 120, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
	};
	if ((YYLIMIT - YYCURSOR) < 6) YYFILL(6);
	yych = *YYCURSOR;
	if (yych <= '/') {
		if (yych <= '"') {
			if (yych <= '\f') {
				if (yych <= 0x08) goto yy108;
				if (yych <= '\t') goto yy103;
				if (yych <= '\n') goto yy105;
				goto yy108;
			} else {
				if (yych <= 0x1F) {
					if (yych <= '\r') goto yy107;
					goto yy108;
				} else {
					if (yych <= ' ') goto yy103;
					if (yych <= '!') goto yy108;
					goto yy89;
				}
			}
		} else {
			if (yych <= '*') {
				if (yych <= '&') goto yy108;
				if (yych <= '\'') goto yy91;
				if (yych <= ')') goto yy96;
				goto yy87;
			} else {
				if (yych <= ',') {
					if (yych <= '+') goto yy97;
					goto yy96;
				} else {
					if (yych <= '-') goto yy108;
					if (yych <= '.') goto yy101;
					goto yy85;
				}
			}
		}
	} else {
		if (yych <= '[') {
			if (yych <= '<') {
				if (yych <= '9') goto yy108;
				if (yych <= ':') goto yy83;
				if (yych <= ';') goto yy96;
				goto yy95;
			} else {
				if (yych <= '?') {
					if (yych <= '>') goto yy96;
					goto yy97;
				} else {
					if (yych <= '@') goto yy108;
					if (yych <= 'Z') goto yy100;
					goto yy93;
				}
			}
		} else {
			if (yych <= 'q') {
				if (yych <= '^') {
					if (yych <= '\\') goto yy96;
					goto yy108;
				} else {
					if (yych == '`') goto yy108;
					goto yy100;
				}
			} else {
				if (yych <= 'z') {
					if (yych <= 'r') goto yy99;
					goto yy100;
				} else {
					if (yych <= '{') goto yy81;
					if (yych <= '|') goto yy96;
					goto yy108;
				}
			}
		}
	}
yy81:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= '@') {
		if (yych <= '/') {
			if (yych == ',') goto yy178;
		} else {
			if (yych <= '0') goto yy175;
			if (yych <= '9') goto yy176;
		}
	} else {
		if (yych <= '_') {
			if (yych <= 'Z') goto yy173;
			if (yych >= '_') goto yy173;
		} else {
			if (yych <= '`') goto yy82;
			if (yych <= 'z') goto yy173;
		}
	}
yy82:
	{
					depth = 1;
					goto code;
				}
yy83:
	YYCTXMARKER = YYCURSOR + 1;
	++YYCURSOR;
	if ((yych = *YYCURSOR) == '=') goto yy169;
yy84:
	{
					std::ostringstream msg;
					msg << "unexpected character: ";
					prtChOrHex(msg, *tok);
					fatal(msg.str().c_str());
					goto scan;
				}
yy85:
	++YYCURSOR;
	if ((yych = *YYCURSOR) == '*') goto yy167;
yy86:
	{
					RETURN(*tok);
				}
yy87:
	++YYCURSOR;
	if ((yych = *YYCURSOR) == '/') goto yy165;
	{
					yylval.op = *tok;
					RETURN(STAR);
				}
yy89:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych != '\n') goto yy161;
yy90:
	{
					fatal("unterminated string constant (missing \")");
				}
yy91:
	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych != '\n') goto yy156;
yy92:
	{
					fatal("unterminated string constant (missing ')");
				}
yy93:
	yyaccept = 3;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == '\n') goto yy94;
	if (yych == '^') goto yy147;
	goto yy146;
yy94:
	{
					fatal("unterminated range (missing ])");
				}
yy95:
	yyaccept = 4;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == '!') goto yy136;
	if (yych == '>') goto yy138;
	goto yy86;
yy96:
	yych = *++YYCURSOR;
	goto yy86;
yy97:
	++YYCURSOR;
	{
					yylval.op = *tok;
					RETURN(CLOSE);
				}
yy99:
	YYCTXMARKER = YYCURSOR + 1;
	yych = *++YYCURSOR;
	if (yych == 'e') goto yy124;
	goto yy113;
yy100:
	YYCTXMARKER = YYCURSOR + 1;
	yych = *++YYCURSOR;
	goto yy113;
yy101:
	++YYCURSOR;
	{
					cur = cursor;
					yylval.regexp = mkDot();
					return RANGE;
				}
yy103:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy111;
yy104:
	{
					goto scan;
				}
yy105:
	++YYCURSOR;
yy106:
	{
					if(cursor == eof) RETURN(0);
					pos = cursor;
					cline++;
					goto scan;
				}
yy107:
	yych = *++YYCURSOR;
	if (yych == '\n') goto yy109;
	goto yy84;
yy108:
	yych = *++YYCURSOR;
	goto yy84;
yy109:
	yych = *++YYCURSOR;
	goto yy106;
yy110:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy111:
	if (yybm[0+yych] & 4) {
		goto yy110;
	}
	goto yy104;
yy112:
	YYCTXMARKER = YYCURSOR + 1;
	++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
yy113:
	if (yybm[0+yych] & 8) {
		goto yy112;
	}
	if (yych <= ' ') {
		if (yych == '\t') goto yy116;
		if (yych <= 0x1F) goto yy115;
		goto yy116;
	} else {
		if (yych <= ',') {
			if (yych <= '+') goto yy115;
			goto yy117;
		} else {
			if (yych <= '<') goto yy115;
			if (yych <= '>') goto yy117;
			goto yy115;
		}
	}
yy114:
	YYCURSOR = YYCTXMARKER;
	{
					if (!FFlag) {
						cur = cursor;
						yylval.symbol = Symbol::find(token());
						return ID;
					} else {
						/* Add one char in front and one behind instead of 's or "s */
						cur = cursor;
						if (bCaseInsensitive || bCaseInverted)
						{
							yylval.regexp = strToCaseInsensitiveRE(raw_token("\""));
						}
						else
						{
							yylval.regexp = strToRE(raw_token("\""));
						}
						return STRING;
					}
				}
yy115:
	yych = *++YYCURSOR;
	goto yy114;
yy116:
	yych = *++YYCURSOR;
	goto yy122;
yy117:
	++YYCURSOR;
yy118:
	YYCURSOR = YYCTXMARKER;
	{
					cur = ptr > tok ? ptr - 1 : cursor;
					yylval.symbol = Symbol::find(token());
					return ID;
				}
yy119:
	++YYCURSOR;
	YYCURSOR = YYCTXMARKER;
	{
					if (FFlag)
					{
						cur = ptr > tok ? ptr - 1 : cursor;
						yylval.symbol = Symbol::find(token());
						return FID;
					} else {
						cur = ptr > tok ? ptr - 1 : cursor;
						yylval.symbol = Symbol::find(token());
						return ID;
					}
				}
yy121:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy122:
	if (yych <= ' ') {
		if (yych == '\t') goto yy121;
		if (yych <= 0x1F) goto yy119;
		goto yy121;
	} else {
		if (yych <= ',') {
			if (yych <= '+') goto yy119;
		} else {
			if (yych <= '<') goto yy119;
			if (yych >= '?') goto yy119;
		}
	}
	yych = *++YYCURSOR;
	goto yy118;
yy124:
	YYCTXMARKER = YYCURSOR + 1;
	yych = *++YYCURSOR;
	if (yych != '2') goto yy113;
	YYCTXMARKER = YYCURSOR + 1;
	yych = *++YYCURSOR;
	if (yych != 'c') goto yy113;
	YYCTXMARKER = YYCURSOR + 1;
	yych = *++YYCURSOR;
	if (yych != ':') goto yy113;
	yych = *++YYCURSOR;
	if (yych <= '^') {
		if (yych <= '@') goto yy114;
		if (yych >= '[') goto yy114;
	} else {
		if (yych == '`') goto yy114;
		if (yych >= '{') goto yy114;
	}
yy128:
	yyaccept = 5;
	YYMARKER = ++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if (yych <= '@') {
		if (yych <= '9') {
			if (yych >= '0') goto yy128;
		} else {
			if (yych <= ':') goto yy133;
			if (yych >= '@') goto yy131;
		}
	} else {
		if (yych <= '_') {
			if (yych <= 'Z') goto yy128;
			if (yych >= '_') goto yy128;
		} else {
			if (yych <= '`') goto yy130;
			if (yych <= 'z') goto yy128;
		}
	}
yy130:
	{
					cur = cursor;
					tok+= 5; /* skip "re2c:" */
					iscfg = 1;
					yylval.str = new Str(token());
					return CONFIG;
				}
yy131:
	yych = *++YYCURSOR;
	if (yych <= '^') {
		if (yych <= '@') goto yy132;
		if (yych <= 'Z') goto yy134;
	} else {
		if (yych == '`') goto yy132;
		if (yych <= 'z') goto yy134;
	}
yy132:
	YYCURSOR = YYMARKER;
	if (yyaccept <= 3) {
		if (yyaccept <= 1) {
			if (yyaccept <= 0) {
				goto yy82;
			} else {
				goto yy90;
			}
		} else {
			if (yyaccept <= 2) {
				goto yy92;
			} else {
				goto yy94;
			}
		}
	} else {
		if (yyaccept <= 5) {
			if (yyaccept <= 4) {
				goto yy86;
			} else {
				goto yy130;
			}
		} else {
			goto yy179;
		}
	}
yy133:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '^') {
		if (yych <= '@') goto yy132;
		if (yych <= 'Z') goto yy128;
		goto yy132;
	} else {
		if (yych == '`') goto yy132;
		if (yych <= 'z') goto yy128;
		goto yy132;
	}
yy134:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 'Z') {
		if (yych <= '/') goto yy130;
		if (yych <= '9') goto yy134;
		if (yych <= '@') goto yy130;
		goto yy134;
	} else {
		if (yych <= '_') {
			if (yych <= '^') goto yy130;
			goto yy134;
		} else {
			if (yych <= '`') goto yy130;
			if (yych <= 'z') goto yy134;
			goto yy130;
		}
	}
yy136:
	++YYCURSOR;
	{
					RETURN(SETUP);
				}
yy138:
	YYCTXMARKER = YYCURSOR + 1;
	yych = *++YYCURSOR;
	goto yy140;
yy139:
	++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
yy140:
	if (yych <= '9') {
		if (yych <= '\t') {
			if (yych <= 0x08) goto yy132;
			goto yy139;
		} else {
			if (yych == ' ') goto yy139;
			goto yy132;
		}
	} else {
		if (yych <= '=') {
			if (yych <= ':') goto yy144;
			if (yych <= '<') goto yy132;
			goto yy143;
		} else {
			if (yych != '{') goto yy132;
		}
	}
yy141:
	++YYCURSOR;
	YYCURSOR = YYCTXMARKER;
	{
					RETURN(NOCOND);
				}
yy143:
	yych = *++YYCURSOR;
	if (yych == '>') goto yy141;
	goto yy132;
yy144:
	yych = *++YYCURSOR;
	if (yych == '=') goto yy141;
	goto yy132;
yy145:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy146:
	if (yybm[0+yych] & 16) {
		goto yy145;
	}
	if (yych <= '[') goto yy132;
	if (yych <= '\\') goto yy149;
	goto yy150;
yy147:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '[') {
		if (yych == '\n') goto yy132;
		goto yy147;
	} else {
		if (yych <= '\\') goto yy152;
		if (yych <= ']') goto yy153;
		goto yy147;
	}
yy149:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy132;
	goto yy145;
yy150:
	++YYCURSOR;
	{
					cur = cursor;
					yylval.regexp = ranToRE(token());
					return RANGE;
				}
yy152:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy132;
	goto yy147;
yy153:
	++YYCURSOR;
	{
					cur = cursor;
					yylval.regexp = invToRE(token());
					return RANGE;
				}
yy155:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy156:
	if (yybm[0+yych] & 32) {
		goto yy155;
	}
	if (yych <= '&') goto yy132;
	if (yych <= '\'') goto yy158;
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy132;
	goto yy155;
yy158:
	++YYCURSOR;
	{
					cur = cursor;
					if (bCaseInverted)
					{
						yylval.regexp = strToRE(token());
					}
					else
					{
						yylval.regexp = strToCaseInsensitiveRE(token());
					}
					return STRING;
				}
yy160:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy161:
	if (yybm[0+yych] & 64) {
		goto yy160;
	}
	if (yych <= '!') goto yy132;
	if (yych <= '"') goto yy163;
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy132;
	goto yy160;
yy163:
	++YYCURSOR;
	{
					cur = cursor;
					if (bCaseInsensitive || bCaseInverted)
					{
						yylval.regexp = strToCaseInsensitiveRE(token());
					}
					else
					{
						yylval.regexp = strToRE(token());
					}
					return STRING;
				}
yy165:
	++YYCURSOR;
	{
					tok = cursor;
					RETURN(0);
				}
yy167:
	++YYCURSOR;
	{
					depth = 1;
					goto comment;
				}
yy169:
	++YYCURSOR;
	if ((yych = *YYCURSOR) == '>') goto yy171;
	{
					cur = cursor;
					tok+= 2; /* skip ":=" */
					depth = 0;
					goto code;
				}
yy171:
	++YYCURSOR;
	YYCURSOR = YYCTXMARKER;
	{
					RETURN(*tok);
				}
yy173:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '^') {
		if (yych <= '9') {
			if (yych <= '/') goto yy132;
			goto yy173;
		} else {
			if (yych <= '@') goto yy132;
			if (yych <= 'Z') goto yy173;
			goto yy132;
		}
	} else {
		if (yych <= 'z') {
			if (yych == '`') goto yy132;
			goto yy173;
		} else {
			if (yych == '}') goto yy192;
			goto yy132;
		}
	}
yy175:
	yych = *++YYCURSOR;
	if (yych == ',') goto yy189;
	goto yy177;
yy176:
	++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
yy177:
	if (yybm[0+yych] & 128) {
		goto yy176;
	}
	if (yych == ',') goto yy182;
	if (yych == '}') goto yy180;
	goto yy132;
yy178:
	++YYCURSOR;
yy179:
	{
					fatal("illegal closure form, use '{n}', '{n,}', '{n,m}' where n and m are numbers");
				}
yy180:
	++YYCURSOR;
	{
					yylval.extop.minsize = atoi((char *)tok+1);
					yylval.extop.maxsize = atoi((char *)tok+1);
					RETURN(CLOSESIZE);
				}
yy182:
	yyaccept = 6;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= '/') goto yy179;
	if (yych <= '9') goto yy185;
	if (yych != '}') goto yy179;
	++YYCURSOR;
	{
					yylval.extop.minsize = atoi((char *)tok+1);
					yylval.extop.maxsize = -1;
					RETURN(CLOSESIZE);
				}
yy185:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '/') goto yy132;
	if (yych <= '9') goto yy185;
	if (yych != '}') goto yy132;
	++YYCURSOR;
	{
					yylval.extop.minsize = atoi((char *)tok+1);
					yylval.extop.maxsize = MAX(yylval.extop.minsize,atoi(strchr((char *)tok, ',')+1));
					RETURN(CLOSESIZE);
				}
yy189:
	yyaccept = 6;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= '/') goto yy179;
	if (yych <= '9') goto yy185;
	if (yych != '}') goto yy179;
	++YYCURSOR;
	{
					yylval.op = '*';
					RETURN(CLOSE);
				}
yy192:
	++YYCURSOR;
	{
					if (!FFlag) {
						fatal("curly braces for names only allowed with -F switch");
					}
					cur = cursor;
					yylval.symbol = Symbol::find(token(1, cur - tok - 2));
					return ID;
				}
}


code:

{
	YYCTYPE yych;
	static const unsigned char yybm[] = {
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192,   0, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192,  64, 192, 192, 192, 192, 128, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192,   0, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
	};
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if (yych <= '&') {
		if (yych <= '\n') {
			if (yych <= 0x00) goto yy202;
			if (yych <= '\t') goto yy204;
			goto yy200;
		} else {
			if (yych == '"') goto yy206;
			goto yy204;
		}
	} else {
		if (yych <= '{') {
			if (yych <= '\'') goto yy207;
			if (yych <= 'z') goto yy204;
			goto yy198;
		} else {
			if (yych != '}') goto yy204;
		}
	}
	++YYCURSOR;
	{
					if (depth == 0)
					{
						fatal("Curly braces are not allowed after ':='");
					}
					else if (--depth == 0)
					{
						cur = cursor;
						yylval.token = new Token(token(), tline);
						return CODE;
					}
					goto code;
				}
yy198:
	++YYCURSOR;
	{
					if (depth == 0)
					{
						fatal("Curly braces are not allowed after ':='");
					}
					else
					{
						++depth;
					}
					goto code;
				}
yy200:
	YYCTXMARKER = YYCURSOR + 1;
	++YYCURSOR;
	if ((yych = *YYCURSOR) <= '\f') {
		if (yych <= 0x08) goto yy201;
		if (yych <= '\n') goto yy215;
	} else {
		if (yych <= '\r') goto yy215;
		if (yych == ' ') goto yy215;
	}
yy201:
	{
					if (depth == 0)
					{
						cur = cursor;
						tok += strspn(tok, " \t\r\n");
						while (cur > tok && strchr(" \t\r\n", cur[-1]))
						{
							--cur;
						}
						yylval.token = new Token(token(), tline);
						return CODE;
					}
					else if (cursor == eof)
					{
						fatal("missing '}'");
					}
					pos = cursor;
					cline++;
					goto code;
				}
yy202:
	++YYCURSOR;
	{
					if (cursor == eof)
					{
						if (depth)
						{
							fatal("missing '}'");
						}
						RETURN(0);
					}
					goto code;
				}
yy204:
	++YYCURSOR;
yy205:
	{
					goto code;
				}
yy206:
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == '\n') goto yy205;
	goto yy213;
yy207:
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == '\n') goto yy205;
	goto yy209;
yy208:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy209:
	if (yybm[0+yych] & 64) {
		goto yy208;
	}
	if (yych <= '&') goto yy210;
	if (yych <= '\'') goto yy204;
	goto yy211;
yy210:
	YYCURSOR = YYMARKER;
	goto yy205;
yy211:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy210;
	goto yy208;
yy212:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy213:
	if (yybm[0+yych] & 128) {
		goto yy212;
	}
	if (yych <= '!') goto yy210;
	if (yych <= '"') goto yy204;
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy210;
	goto yy212;
yy215:
	++YYCURSOR;
	YYCURSOR = YYCTXMARKER;
	{
					if (depth == 0)
					{
						goto code;
					}
					else if (cursor == eof)
					{
						fatal("missing '}'");
					}
					pos = cursor;
					cline++;
					goto code;
				}
}


comment:

{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if (yych <= ')') {
		if (yych == '\n') goto yy222;
		goto yy224;
	} else {
		if (yych <= '*') goto yy219;
		if (yych == '/') goto yy221;
		goto yy224;
	}
yy219:
	++YYCURSOR;
	if ((yych = *YYCURSOR) == '/') goto yy227;
yy220:
	{
					if(cursor == eof)
					{
						RETURN(0);
					}
					goto comment;
				}
yy221:
	yych = *++YYCURSOR;
	if (yych == '*') goto yy225;
	goto yy220;
yy222:
	++YYCURSOR;
	{
					if(cursor == eof)
					{
						RETURN(0);
					}
					tok = pos = cursor;
					cline++;
					goto comment;
				}
yy224:
	yych = *++YYCURSOR;
	goto yy220;
yy225:
	++YYCURSOR;
	{
					++depth;
					fatal("ambiguous /* found");
					goto comment;
				}
yy227:
	++YYCURSOR;
	{
					if(--depth == 0)
					{
						goto scan;
					}
					else
					{
						goto comment;
					}
				}
}


config:

{
	YYCTYPE yych;
	static const unsigned char yybm[] = {
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0, 128,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		128,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
	};
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if (yych <= 0x1F) {
		if (yych != '\t') goto yy235;
	} else {
		if (yych <= ' ') goto yy231;
		if (yych == '=') goto yy233;
		goto yy235;
	}
yy231:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy240;
yy232:
	{
					goto config;
				}
yy233:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy238;
yy234:
	{
					iscfg = 2;
					cur = cursor;
					RETURN('=');
				}
yy235:
	++YYCURSOR;
	{
					fatal("missing '='");
				}
yy237:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy238:
	if (yybm[0+yych] & 128) {
		goto yy237;
	}
	goto yy234;
yy239:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy240:
	if (yych == '\t') goto yy239;
	if (yych == ' ') goto yy239;
	goto yy232;
}


value:

{
	YYCTYPE yych;
	static const unsigned char yybm[] = {
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 192,   0, 248, 248, 192, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		192, 248, 104, 248, 248, 248, 248, 152, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		252, 252, 252, 252, 252, 252, 252, 252, 
		252, 252, 248, 192, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248,   8, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
	};
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if (yych <= '&') {
		if (yych <= '\r') {
			if (yych <= 0x08) goto yy249;
			if (yych <= '\n') goto yy243;
			if (yych <= '\f') goto yy249;
		} else {
			if (yych <= ' ') {
				if (yych <= 0x1F) goto yy249;
			} else {
				if (yych == '"') goto yy251;
				goto yy249;
			}
		}
	} else {
		if (yych <= '/') {
			if (yych <= '\'') goto yy253;
			if (yych == '-') goto yy246;
			goto yy249;
		} else {
			if (yych <= '9') {
				if (yych <= '0') goto yy244;
				goto yy247;
			} else {
				if (yych != ';') goto yy249;
			}
		}
	}
yy243:
	{
					cur = cursor;
					yylval.str = new Str(token());
					iscfg = 0;
					return VALUE;
				}
yy244:
	++YYCURSOR;
	if (yybm[0+(yych = *YYCURSOR)] & 8) {
		goto yy249;
	}
yy245:
	{
					cur = cursor;
					yylval.number = atoi(token().to_string().c_str());
					iscfg = 0;
					return NUMBER;
				}
yy246:
	yych = *++YYCURSOR;
	if (yych <= '0') goto yy250;
	if (yych >= ':') goto yy250;
yy247:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yybm[0+yych] & 4) {
		goto yy247;
	}
	if (yych <= '\r') {
		if (yych <= 0x08) goto yy249;
		if (yych <= '\n') goto yy245;
		if (yych >= '\r') goto yy245;
	} else {
		if (yych <= ' ') {
			if (yych >= ' ') goto yy245;
		} else {
			if (yych == ';') goto yy245;
		}
	}
yy249:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy250:
	if (yybm[0+yych] & 8) {
		goto yy249;
	}
	goto yy243;
yy251:
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yybm[0+yych] & 16) {
		goto yy251;
	}
	if (yych <= '!') {
		if (yych == '\n') goto yy243;
		goto yy261;
	} else {
		if (yych <= '"') goto yy249;
		if (yych <= '[') goto yy261;
		goto yy263;
	}
yy253:
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yybm[0+yych] & 32) {
		goto yy253;
	}
	if (yych <= '&') {
		if (yych == '\n') goto yy243;
	} else {
		if (yych <= '\'') goto yy249;
		if (yych >= '\\') goto yy258;
	}
yy255:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yybm[0+yych] & 64) {
		goto yy255;
	}
	if (yych <= '&') goto yy257;
	if (yych <= '\'') goto yy259;
	goto yy260;
yy257:
	YYCURSOR = YYMARKER;
	goto yy243;
yy258:
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '\r') {
		if (yych <= '\t') {
			if (yych <= 0x08) goto yy253;
			goto yy255;
		} else {
			if (yych <= '\n') goto yy243;
			if (yych <= '\f') goto yy253;
			goto yy255;
		}
	} else {
		if (yych <= ' ') {
			if (yych <= 0x1F) goto yy253;
			goto yy255;
		} else {
			if (yych == ';') goto yy255;
			goto yy253;
		}
	}
yy259:
	yych = *++YYCURSOR;
	goto yy243;
yy260:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy257;
	goto yy255;
yy261:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yybm[0+yych] & 128) {
		goto yy261;
	}
	if (yych <= '!') goto yy257;
	if (yych <= '"') goto yy259;
	goto yy264;
yy263:
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '\r') {
		if (yych <= '\t') {
			if (yych <= 0x08) goto yy251;
			goto yy261;
		} else {
			if (yych <= '\n') goto yy243;
			if (yych <= '\f') goto yy251;
			goto yy261;
		}
	} else {
		if (yych <= ' ') {
			if (yych <= 0x1F) goto yy251;
			goto yy261;
		} else {
			if (yych == ';') goto yy261;
			goto yy251;
		}
	}
yy264:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy257;
	goto yy261;
}

}

void Scanner::set_in_parse(bool new_in_parse)
{
	in_parse = new_in_parse;
}

void Scanner::fatal_at(uint line, uint ofs, const char *msg) const
{
	out.flush();
	std::cerr << "re2c: error: "
		<< "line " << line << ", column " << (tchar + ofs + 1) << ": "
		<< msg << std::endl;
	exit(1);
}

void Scanner::fatal(uint ofs, const char *msg) const
{
	fatal_at(in_parse ? tline : cline, ofs, msg);
}

void Scanner::fatalf_at(uint line, const char* fmt, ...) const
{
	char szBuf[4096];

	va_list args;
	
	va_start(args, fmt);
	vsnprintf(szBuf, sizeof(szBuf), fmt, args);
	va_end(args);
	
	szBuf[sizeof(szBuf)-1] = '0';
	
	fatal_at(line, 0, szBuf);
}

void Scanner::fatalf(const char *fmt, ...) const
{
	char szBuf[4096];

	va_list args;
	
	va_start(args, fmt);
	vsnprintf(szBuf, sizeof(szBuf), fmt, args);
	va_end(args);
	
	szBuf[sizeof(szBuf)-1] = '0';
	
	fatal(szBuf);
}

Scanner::~Scanner()
{
	if (bot)
	{
		delete [] bot;
	}
}

void Scanner::check_token_length(char *pos, uint len) const
{
	if (pos < bot || pos + len >= top)
	{
		fatal("Token exceeds limit");
	}
}

SubStr Scanner::raw_token(std::string enclosure) const
{
	return SubStr(std::string(enclosure + token().to_string() + enclosure).c_str());
}

} // end namespace re2c
