#pragma once

namespace r2
{
	struct Point
	{
		bool operator==( const Point& p ) const
		{
			return x == p.x && y == p.y;
		}
		bool operator!=( const Point& p ) const
		{
			return !( *this == p );
		}
		Point operator+( const Point& p ) const
		{
			return Point{ x + p.x, y + p.y };
		}

		int x = 0;
		int y = 0;
	};
}