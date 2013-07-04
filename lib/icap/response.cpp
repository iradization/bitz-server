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

#include "response.h"


namespace icap {

	Response::Response( ResponseHeader * header ) {

		if ( header != NULL ) {
			_header = header;
			_cleanup_header  = false;
		} else {
			_header = new ResponseHeader( ResponseHeader::SERVER_ERROR );
			_cleanup_header  = true;
		}

		// initialise defaults
		_payload.req_header = "";
		_payload.req_body   = "";
		_payload.res_header = "";
		_payload.res_body   = "";
		_payload.ieof       = false;

	}


	Response::Response( ResponseHeader::status_t status ) {
		_header = new ResponseHeader( status );
		_cleanup_header  = true;
	}


	Response::~Response() {

		// cleanup
		if ( _cleanup_header ) {
			delete _header;
		}

	}


	ResponseHeader * const Response::header() const throw() {
		return _header;
	}


	void Response::payload( payload_t payload ) throw() {

		_payload = payload;

		// update encapsulated data
		_header->update_encapsulated( _payload );

	}


	const payload_t &Response::payload() const throw() {
		return _payload;
	}

} /* end of namespace icap */

