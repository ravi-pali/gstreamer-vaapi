/*
 *  gstvaapidisplay_priv.h - Base VA display (private definitions)
 *
 *  gstreamer-vaapi (C) 2010 Splitted-Desktop Systems
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#ifndef GST_VAAPI_DISPLAY_PRIV_H
#define GST_VAAPI_DISPLAY_PRIV_H

#include <gst/vaapi/gstvaapidisplay.h>

G_BEGIN_DECLS

#define GST_VAAPI_DISPLAY_GET_PRIVATE(obj)                      \
    (G_TYPE_INSTANCE_GET_PRIVATE((obj),                         \
                                 GST_VAAPI_TYPE_DISPLAY,	\
                                 GstVaapiDisplayPrivate))

#define GST_VAAPI_DISPLAY_CAST(display) ((GstVaapiDisplay *)(display))

/**
 * GST_VAAPI_DISPLAY_VADISPLAY:
 * @display_: a #GstVaapiDisplay
 *
 * Macro that evaluates to the #VADisplay of @display.
 * This is an internal macro that does not do any run-time type check.
 */
#define GST_VAAPI_DISPLAY_VADISPLAY(display_) \
    GST_VAAPI_DISPLAY_CAST(display_)->priv->display

/**
 * GST_VAAPI_DISPLAY_LOCK:
 * @display: a #GstVaapiDisplay
 *
 * Locks @display
 */
#define GST_VAAPI_DISPLAY_LOCK(display) \
    gst_vaapi_display_lock(display)

/**
 * GST_VAAPI_DISPLAY_UNLOCK:
 * @display: a #GstVaapiDisplay
 *
 * Unlocks @display
 */
#define GST_VAAPI_DISPLAY_UNLOCK(display) \
    gst_vaapi_display_unlock(display)

/**
 * GstVaapiDisplayPrivate:
 *
 * Base class for VA displays.
 */
struct _GstVaapiDisplayPrivate {
    GStaticMutex        mutex;
    VADisplay           display;
    guint               width;
    guint               height;
    guint               width_mm;
    guint               height_mm;
    guint               par_n;
    guint               par_d;
    GArray             *profiles;
    GArray             *image_formats;
    GArray             *subpicture_formats;
    guint               create_display  : 1;
};

G_END_DECLS

#endif /* GST_VAAPI_DISPLAY_PRIV_H */
