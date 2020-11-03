//! -------------------------------------------------------------------------
//!
//! Copyright (C) 2016 CC0 1.0 Universal (CC0 1.0)
//!
//! The person who associated a work with this deed has dedicated the work to
//! the public domain by waiving all of his or her rights to the work
//! worldwide under copyright law, including all related and neighboring
//! rights, to the extent allowed by law.
//!
//! You can copy, modify, distribute and perform the work, even for commercial
//! purposes, all without asking permission.
//!
//! See the complete legal text at
//! <https://creativecommons.org/publicdomain/zero/1.0/legalcode>
//!
//! -------------------------------------------------------------------------

#include <pybind11/pybind11.h>
#include <pybind11/operators.h>

#include <itpp/comm/bch.h>

namespace py = pybind11;

void generate_pybind_wrapper_for_itpp_bch_class ( py::module &m) {
  py::class_<itpp::BCH>( m, "bch")
    .def( py::init<short, short, bool>(), py::arg("in_n"), py::arg("in_t"), py::arg("sys")=false)

    .def("encode", static_cast<void (itpp::BCH::*)(const itpp::bvec&, itpp::bvec&)>(&itpp::BCH::encode)
                 	, py::arg( "uncoded_bits"), py::arg("coded_bits"))

    .def("decode", static_cast<void (itpp::BCH:*)(const itpp::bvec&, itpp::bvec&)>(&itpp::BCH::decode)
                 	, py::arg( "coded_bits"), py::arg("decoded_bits"))
  ;
}

