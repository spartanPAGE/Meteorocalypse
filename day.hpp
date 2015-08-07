#pragma once

class Day{
public:
    using Number = unsigned;
public:
    Day(Number);
public:
    Number number() const;
private:
    Number id;
};

