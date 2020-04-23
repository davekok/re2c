<?php

declare(strict_types=1);

const yyc0 = 0;
const yycmain = 1;
const yycdqs = 2;

class Lexer implements Iterator
{
	public const ERROR = 0;

	/*!re2c
		SPACE = [\t\n\v\r ]+;
	*/
	public const SPACE = 1;

	/*!re2c
		NUMBER = [0-9]+;
	*/
	public const NUMBER = 2;

	/*!re2c
		NAME = [A-Za-z_][A-Za-z0-9_]*;
	*/
	public const NAME = 3;

	/*!re2c
		DQ = [\"];
	*/
	public const DQ = 4;

	/*!re2c
		ESCAPE = [\\][0tnvr\\"];
	*/
	public const ESCAPE = 5;

	/*!re2c
		STR = [\x20\x21\x23-\x5B\x5D-\x7E\x80-\xFF]+;
	*/
	public const STR = 6;

	private string $buffer;
	private int $cursor = 0;
	private int $marker = 0;
	private int $offset = 0;
	private int $length;
	private int $condition;

	public function __construct(string $buffer)
	{
		$this->buffer = $buffer;
		$this->length = strlen($buffer);
	}

	public function current()
	{
		return [$this->token, $this->value];
	}

	public function key()
	{
		return $this->offset;
	}

	public function rewind(): void
	{
		$this->condition = 0;
		$this->cursor = 0;
		$this->marker = 0;
		$this->offset = 0;
		$this->next();
	}

	public function valid(): bool
	{
		return $this->offset < $this->length;
	}

	public function setToken(int $token): void
	{
		$this->offset = $this->marker;
		$this->token = $token;
		$this->value = substr($this->buffer, $this->marker, $this->cursor - $this->marker);
		$this->marker = $this->cursor;
	}

	public function getCondition(): int
	{
		return $this->condition;
	}

	public function setCondition(int $condition): void
	{
		$this->condition = $condition;
	}

	public function next(): void
	{
		/*!re2c
			re2c:yyfill:enable = 0;

			<>             :=> main
			<*>     *      { $this->setToken(self::ERROR);  return; }
			<main>  NUMBER { $this->setToken(self::NUMBER); return; }
			<main>  SPACE  { $this->setToken(self::SPACE);  return; }
			<main>  NAME   { $this->setToken(self::NAME);   return; }
			<main>  DQ     :=> dqs
			<dqs>   ESCAPE { $this->setToken(self::ESCAPE); return; }
			<dqs>   STR    { $this->setToken(self::STR);    return; }
			<dqs>   DQ     :=> main
		*/
	}
}

$lexer = new Lexer('AName 394857 "sdf"');
foreach ($lexer as $offset => [$token, $value])
	echo "[$offset] $token: $value\n";
