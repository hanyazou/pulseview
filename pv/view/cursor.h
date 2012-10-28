/*
 * This file is part of the PulseView project.
 *
 * Copyright (C) 2012 Joel Holdsworth <joel@airwebreathe.org.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#ifndef PULSEVIEW_PV_VIEW_CURSOR_H
#define PULSEVIEW_PV_VIEW_CURSOR_H

#include "timemarker.h"

namespace pv {
namespace view {

class Cursor : public TimeMarker
{
private:
	static const QColor LineColour;
	static const QColor FillColour;
	static const QColor HighlightColour;

	static const int Size;
	static const int Offset;

public:
	/**
	 * Constructor.
	 * @param colour A reference to the colour of this cursor.
	 * @param time The time to set the flag to.
	 */
	Cursor(const View &view, double time);

public:
	/**
	 * Paints the cursor's label to the ruler.
	 * @param p The painter to draw with.
	 * @param rect The rectangle of the ruler client area.
	 */
	void paint_label(QPainter &p, const QRect &rect);
};

} // namespace view
} // namespace pv

#endif // PULSEVIEW_PV_VIEW_CURSOR_H