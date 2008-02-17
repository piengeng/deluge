// Copyright Andrew Resch 2008. Use, modification and distribution is
// subject to the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <libtorrent/ip_filter.hpp>
#include <boost/python.hpp>
#include "gil.hpp"

using namespace boost::python;
using namespace libtorrent;

namespace
{
    void add_rule(ip_filter& filter, std::string start, std::string end, int flags)
    {
        return filter.add_rule(address_v4::from_string(start), address_v4::from_string(end), flags);
    }
}

void bind_ip_filter()
{
    class_<ip_filter>("ip_filter")
        .def("add_rule", &add_rule)
        .def("access", allow_threads(&ip_filter::access))
        .def_readonly("export_filter", allow_threads(&ip_filter::export_filter))
    ;
}
