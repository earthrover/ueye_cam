/*******************************************************************************
* SOFTWARE LICENSE AGREEMENT (BSD LICENSE):
*
* Copyright (c) 2013-2021, Anqi Xu and contributors
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
*  * Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*  * Redistributions in binary form must reproduce the above
*    copyright notice, this list of conditions and the following
*    disclaimer in the documentation and/or other materials provided
*    with the distribution.
*  * Neither the name of the School of Computer Science, McGill University,
*    nor the names of its contributors may be used to endorse or promote
*    products derived from this software without specific prior written
*    permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

/*****************************************************************************
 ** Includes
 *****************************************************************************/

#include <set>
#include <sstream>
#include <string>

#include <ueye.h>

#include "../../include/ueye_cam/utilities.hpp"


/*****************************************************************************
 ** Namespaces
 *****************************************************************************/

namespace ueye_cam
{

/*****************************************************************************
 ** Implementation
 *****************************************************************************/

bool has_intersection(const std::set<std::string>& s1, const std::set<std::string>& s2) {
  for (const std::string& s: s1) {
    if (s2.find(s) != s2.end()) { return true; }
  }
  for (const std::string& s: s2) {
    if (s1.find(s) != s1.end()) { return true; }
  }
  return false;
}

std::string sdk_version() {

	// Fetch from the library, this also helps confirm that the library is
    // available. Alternatively, just fetch UEYE_VERSION_CODE from the header.
    int version = is_GetDLLVersion();
    int major_version = version >> 24;
    int minor_version = (version - (major_version << 24)) >> 16;
    int patch_version = (version - (major_version << 24) - (minor_version << 16));
    std::ostringstream ostream;
    ostream << major_version << "." << minor_version << "." << patch_version;
    return ostream.str();
}


std::string sdk_required_version() {
	return std::string("4.94.0+");
}

} // namespace ueye_cam