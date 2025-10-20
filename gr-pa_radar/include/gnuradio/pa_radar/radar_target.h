/* -*- c++ -*- */
/*
 * Copyright 2025 iky.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_PA_RADAR_RADAR_TARGET_H
#define INCLUDED_PA_RADAR_RADAR_TARGET_H

#include <gnuradio/pa_radar/api.h>
#include <gnuradio/sync_block.h>

namespace gr
{
namespace pa_radar
{

/*!
 * \brief <+description of block+>
 * \ingroup pa_radar
 *
 */
class PA_RADAR_API radar_target : virtual public gr::sync_block
{
  public:
    typedef std::shared_ptr<radar_target> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of pa_radar::radar_target.
     *
     * To avoid accidental use of raw pointers, pa_radar::radar_target's
     * constructor is in a private implementation
     * class. pa_radar::radar_target::make is the public interface for
     * creating new instances.
     */
    static sptr make(double range_m, double rcs_m2);
};

} // namespace pa_radar
} // namespace gr

#endif /* INCLUDED_PA_RADAR_RADAR_TARGET_H */
