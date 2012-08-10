/* 
 * Copyright © 2012 Intel Corporation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Benjamin Segovia <benjamin.segovia@intel.com>
 */

#ifndef __GBE_STRING_HPP__
#define __GBE_STRING_HPP__

#include "sys/platform.hpp"
#include "sys/filename.hpp"

#include <cstring>
#include <string>
#include <sstream>
#include <fstream>

namespace std
{
  string strlwr(const string& s);
  string strupr(const string& s);
  template<typename T> INLINE string stringOf(const T& v) {
    stringstream s; s << v; return s.str();
  }
} /* namespace std */

namespace gbe
{
  /*! Compare two strings */
  bool strequal(const char *s1, const char *s2);
  /*! Say if needle is in haystack */
  bool contains(const char *haystack, const char *needle);
  /*! Tokenize a string (like strtok_r does) */
  char* tokenize(char *s1, const char *s2, char **lasts);
  /*! Load a file from its path and copies it into a string */
  std::string loadFile(const FileName &path);
  /*! Load a file from a stream and copies it into a string */
  std::string loadFile(std::ifstream &stream);
} /* namespace gbe */

#endif /* __GBE_STRING_HPP__ */

