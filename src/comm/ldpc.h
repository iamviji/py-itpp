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

#include <itpp/comm/ldpc.h>

namespace py = pybind11;

void generate_pybind_wrapper_for_itpp_ldpc_code_class( py::module &m) {

  py::class_<itpp::LDPC_Code>( m, "LDPC_Code" )
    .def( py::init<>() )

    .def("set_code", &itpp::LDPC_Code::set_code
                         ,  py::arg( "H"), py::arg("G"), py::arg("perform_integrity_check") = true)
    .def("set_decoding_method", &itpp::LDPC_Code::set_decoding_method
                         ,  py::arg( "method"))
    .def("set_exit_conditions", &itpp::LDPC_Code::set_exit_conditions
                         ,  py::arg( "max_iters"), py::arg("syndr_check_each_iter") = true, py::arg("syndr_check_at_start")=false)

    .def("encode", &itpp::LDPC_Code::encode
                 	, py::arg( "input"), py::arg("output"))

    .def("decode", static_cast<void (itpp::LDPC_Code::*)(const itpp::vec&, itpp::bvec&)
                 	, py::arg( "llr_in"), py::arg("syst_bits"))
  ;
}
