/*
 *	C++ ICAP library
 *	Copyright (C) 2012	Uditha Atukorala
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program; if not, write to the Free Software
 *	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "response_header.h"


namespace icap {

	ResponseHeader::ResponseHeader( status_t status ) : Header() {

		// FIXME: protocol shouldn't be hard-coded
		_response.protocol = "ICAP/1.0";
		_response.status   = status;

	}

	ResponseHeader::~ResponseHeader() { }

	const std::string &ResponseHeader::protocol() throw() {
		return _response.protocol;
	}

	const ResponseHeader::status_t &ResponseHeader::status() throw() {
		return _response.status;
	}

} /* end of namespace icap */
