/* -*- c++ -*- */
/*
 * Copyright 2025 iky.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "radar_target_impl.h"
#include <gnuradio/io_signature.h>

namespace gr
{
namespace pa_radar
{

#pragma message("set the following appropriately and remove this warning")
using input_type = float;
#pragma message("set the following appropriately and remove this warning")
using output_type = float;
radar_target::sptr radar_target::make(double range_m, double rcs_m2)
{
    return gnuradio::make_block_sptr<radar_target_impl>(range_m, rcs_m2);
}

/*
 * The private constructor
 */
radar_target_impl::radar_target_impl(double range_m, double rcs_m2)
    : gr::sync_block(
          "radar_target",
          gr::io_signature::make(1 /* min inputs */, 1 /* max inputs */, sizeof(input_type)),
          gr::io_signature::make(1 /* min outputs */, 1 /*max outputs */, sizeof(output_type)))
{
}

/*
 * Our virtual destructor.
 */
radar_target_impl::~radar_target_impl() {}

int radar_target_impl::work(int noutput_items, gr_vector_const_void_star &input_items,
                            gr_vector_void_star &output_items)
{
    auto in = static_cast<const input_type *>(input_items[0]);
    auto out = static_cast<output_type *>(output_items[0]);

#pragma message("Implement the signal processing in your block and remove this warning")
    // Do <+signal processing+>

    // Tell runtime system how many output items we produced.
    return noutput_items;
}

} /* namespace pa_radar */
} /* namespace gr */
