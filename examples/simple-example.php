<?php

declare(strict_types=1);

/*!re2c
    re2c:yyfill:enable  = 0;

    digit  = [0-9];
    number = digit+;
    comma = ",";
*/
class Lexer implements Iterator
{
    public const ERROR = 0;
    public const NUMBER = 1;
    public const COMMA = 2;
    private string $buffer;
    private int $marker;
    private int $offset;
    private int $cursor;
    private int $length;

    public function __construct($buffer)
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

    public function valid(): bool
    {
        return $this->token !== self::ERROR && $this->cursor < $this->length;
    }

    public function rewind(): void
    {
        $this->cursor = 0;
        $this->offset = 0;
        $this->marker = 0;
        $this->next();
    }

    public function next(): void
    {
        /*!re2c
        *
        {
            $this->offset = $this->marker;
            $this->token = self::ERROR;
            $this->value = substr($this->buffer, $this->marker, $this->cursor - $this->marker);
            $this->marker = $this->cursor;
            return;
        }

        comma
        {
            $this->offset = $this->marker;
            $this->token = self::COMMA;
            $this->value = substr($this->buffer, $this->marker, $this->cursor - $this->marker);
            $this->marker = $this->cursor;
            return;
        }

        number
        {
            $this->offset = $this->marker;
            $this->token = self::NUMBER;
            $this->value = substr($this->buffer, $this->marker, $this->cursor - $this->marker);
            $this->marker = $this->cursor;
            return;
        }
        */
    }
}

foreach ((new Lexer("843954,3948,30454")) as $offset => [$token, $value])
    echo "[$offset] $token: $value\n";
