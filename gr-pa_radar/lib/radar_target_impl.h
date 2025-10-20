/* -*- c++ -*- */
/*
 * Copyright 2025 iky.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_PA_RADAR_RADAR_TARGET_IMPL_H
#define INCLUDED_PA_RADAR_RADAR_TARGET_IMPL_H

#include <gnuradio/pa_radar/radar_target.h>

namespace gr
{
namespace pa_radar
{

class radar_target_impl : public radar_target
{
  private:
    // Nothing to declare in this block.

  public:
    radar_target_impl(double range_m, double rcs_m2);
    ~radar_target_impl();

    // Where all the action really happens
    int work(int noutput_items, gr_vector_const_void_star &input_items,
             gr_vector_void_star &output_items);
};

} // namespace pa_radar
} // namespace gr

#endif /* INCLUDED_PA_RADAR_RADAR_TARGET_IMPL_H */
