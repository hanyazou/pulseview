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

#ifndef PULSEVIEW_PV_PROP_ENUM_H
#define PULSEVIEW_PV_PROP_ENUM_H

#include <utility>
#include <vector>

#include <glib-2.0/glib.h>
#include "property.h"

class QComboBox;

namespace pv {
namespace prop {

class Enum : public Property
{
public:
	Enum(QString name,
		std::vector<std::pair<const void*, QString> > values,
		boost::function<GVariant* ()> getter,
		boost::function<void (GVariant*)> setter);

	QWidget* get_widget(QWidget *parent);

	void commit();

private:
	const std::vector< std::pair<const void*, QString> > _values;
	boost::function<GVariant* ()> _getter;
	boost::function<void (GVariant*)> _setter;

	QComboBox *_selector;
};

} // prop
} // pv

#endif // PULSEVIEW_PV_PROP_ENUM_H
