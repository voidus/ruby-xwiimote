#include "ruby.h"
#include "ruby-xwiimote.h"
#include <xwiimote.h>

VALUE mXWiimote;

VALUE mXWiiMote_EventTypes;

/*
 * Document-module: XWiimote::EventTypes
 *
 * Contains constants from xwii_event_types
 */
void initialize_event_types() {
  VALUE mXWiimote_EventTypes = rb_define_module_under(mXWiimote, "EventTypes");

  /**
   * Document-const: XWiimote::EventTypes::KEY
   *
   * Core-interface key event
   *
   * The payload of such events is struct xwii_event_key. Valid
   * key-events include all the events reported by the core-interface,
   * which is normally only LEFT, RIGHT, UP, DOWN, A, B, PLUS, MINUS,
   * HOME, ONE, TWO.
   */
  rb_define_const(mXWiimote_EventTypes, "KEY", INT2NUM(XWII_EVENT_KEY));

  /**
   * Document_const: XWiimote::EventTypes::ACCEL
   *
   * Accelerometer event
   *
   * Provides accelerometer data. Payload is struct xwii_event_abs
   * and only the first element in the abs-array is used. The x, y and z
   * fields contain the accelerometer data.
   * Note that the accelerometer reports acceleration data, not speed
   * data!
   */
  rb_define_const(mXWiimote_EventTypes, "ACCEL", INT2NUM(XWII_EVENT_ACCEL));

  /**
   * Document-const: XWiimote::EventTypes::IR
   *
   * IR-Camera event
   *
   * Provides IR-camera events. The camera can track up two four IR
   * sources. As long as a single source is tracked, it stays at it's
   * pre-allocated slot. The four available slots are reported as
   * struct xwii_event_abs
   * payload. The x and y fields contain the position of each slot.
   *
   * Use xwii_event_ir_is_valid() to see whether a specific slot is
   * currently valid or whether it currently doesn't track any IR source.
   */
  rb_define_const(mXWiimote_EventTypes, "IR", INT2NUM(XWII_EVENT_IR));

  /**
   * Document-const: XWiimote::EventTypes::BALANCE_BOARD
   *
   * Balance-Board event
   *
   * Provides balance-board weight data. Four sensors report weight-data
   * for each of the four edges of the board. The data is available as
   * struct xwii_event_abs
   * payload. The x fields of the first four array-entries contain the
   * weight-value.
   */
  rb_define_const(mXWiimote_EventTypes, "BALANCE_BOARD", INT2NUM(XWII_EVENT_BALANCE_BOARD));

  /**
   * Document-const: XWiimote::EventTypes::MOTION_PLUS
   *
   * Motion-Plus event
   *
   * Motion-Plus gyroscope events. These describe rotational speed, not
   * acceleration, of the motion-plus extension. The payload is available
   * as struct xwii_event_abs
   * and the x, y and z field of the first array-element describes the
   * motion-events in the 3 dimensions.
   */
  rb_define_const(mXWiimote_EventTypes, "MOTION_PLUS", INT2NUM(XWII_EVENT_MOTION_PLUS));

  /**
   * Document-const: XWiimote::EventTypes::PRO_CONTROLLER_KEY
   *
   * Pro-Controller key event
   *
   * Button events of the pro-controller are reported via this interface
   * and not via the core-interface (which only reports core-buttons).
   * Valid buttons include: LEFT, RIGHT, UP, DOWN, PLUS, MINUS, HOME, X,
   * Y, A, B, TR, TL, ZR, ZL, THUMBL, THUMBR.
   * Payload type is struct xwii_event_key.
   */
  rb_define_const(mXWiimote_EventTypes, "PRO_CONTROLLER_KEY", INT2NUM(XWII_EVENT_PRO_CONTROLLER_KEY));

  /**
   * Document-const: XWiimote::EventTypes::PRO_CONTROLLER_MOVE
   *
   * Pro-Controller movement event
   *
   * Movement of analog sticks are reported via this event. The payload
   * is a struct xwii_event_abs
   * and the first two array elements contain the absolute x and y
   * position of both analog sticks.
   */
  rb_define_const(mXWiimote_EventTypes, "PRO_CONTROLLER_MOVE", INT2NUM(XWII_EVENT_PRO_CONTROLLER_MOVE));

  /**
   * Document-const: XWiimote::EventTypes::WATCH
   *
   * Hotplug Event
   *
   * This event is sent whenever an extension was hotplugged (plugged or
   * unplugged), a device-detection finished or some other static data
   * changed which cannot be monitored separately. No payload is provided.
   * An application should check what changed by examining the device is
   * testing whether all required interfaces are still available.
   * Non-hotplug aware devices may discard this event.
   *
   * This is only returned if you explicitly watched for hotplug events.
   * See xwii_iface_watch().
   *
   * This event is also returned if an interface is closed because the
   * kernel closed our file-descriptor (for whatever reason). This is
   * returned regardless whether you watch for hotplug events or not.
   */
  rb_define_const(mXWiimote_EventTypes, "WATCH", INT2NUM(XWII_EVENT_WATCH));

  /**
   * Document-const: XWiimote::EventTypes::CLASSIC_CONTROLLER_KEY
   *
   * Classic Controller key event
   *
   * Button events of the classic controller are reported via this
   * interface and not via the core-interface (which only reports
   * core-buttons).
   * Valid buttons include: LEFT, RIGHT, UP, DOWN, PLUS, MINUS, HOME, X,
   * Y, A, B, TR, TL, ZR, ZL.
   * Payload type is struct xwii_event_key.
   */
  rb_define_const(mXWiimote_EventTypes, "CLASSIC_CONTROLLER_KEY", INT2NUM(XWII_EVENT_CLASSIC_CONTROLLER_KEY));

  /**
   * Document-const: XWiimote::EventTypes::CLASSIC_CONTROLLER_MOVE
   *
   * Classic Controller movement event
   *
   * Movement of analog sticks are reported via this event. The payload
   * is a struct xwii_event_abs and the first two array elements contain
   * the absolute x and y position of both analog sticks.
   * The x value of the third array element contains the absolute position
   * of the TL trigger. The y value contains the absolute position for the
   * TR trigger. Note that many classic controllers do not have analog
   * TL/TR triggers, in which case these read 0 or MAX (63). The digital
   * TL/TR buttons are always reported correctly.
   */
  rb_define_const(mXWiimote_EventTypes, "CLASSIC_CONTROLLER_MOVE", INT2NUM(XWII_EVENT_CLASSIC_CONTROLLER_MOVE));

  /**
   * Document-const: XWiimote::EventTypes::NUNCHUK_KEY
   *
   * Nunchuk key event
   *
   * Button events of the nunchuk controller are reported via this
   * interface and not via the core-interface (which only reports
   * core-buttons).
   * Valid buttons include: C, Z
   * Payload type is struct xwii_event_key.
   */
  rb_define_const(mXWiimote_EventTypes, "NUNCHUK_KEY", INT2NUM(XWII_EVENT_NUNCHUK_KEY));

  /**
   * Document-const: XWiimote::EventTypes::NUNCHUK_MOVE
   *
   * Nunchuk movement event
   *
   * Movement events of the nunchuk controller are reported via this
   * interface. Payload is of type struct xwii_event_abs. The first array
   * element contains the x/y positions of the analog stick. The second
   * array element contains the accelerometer information.
   */
  rb_define_const(mXWiimote_EventTypes, "NUNCHUK_MOVE", INT2NUM(XWII_EVENT_NUNCHUK_MOVE));

  /**
   * Document-const: XWiimote::EventTypes::DRUMS_KEY
   *
   * Drums key event
   *
   * Button events for drums controllers. Valid buttons are PLUS and MINUS
   * for the +/- buttons on the center-bar.
   * Payload type is struct xwii_event_key.
   */
  rb_define_const(mXWiimote_EventTypes, "DRUMS_KEY", INT2NUM(XWII_EVENT_DRUMS_KEY));

  /**
   * Document-const: XWiimote::EventTypes::DRUMS_MOVE
   *
   * Drums movement event
   *
   * Movement and pressure events for drums controllers. Payload is of
   * type struct xwii_event_abs. The indices are describe as
   * enum xwii_drums_abs and each of them contains the corresponding
   * stick-movement or drum-pressure values.
   */
  rb_define_const(mXWiimote_EventTypes, "DRUMS_MOVE", INT2NUM(XWII_EVENT_DRUMS_MOVE));

  /**
   * Document-const: XWiimote::EventTypes::GUITAR_KEY
   *
   * Guitar key event
   *
   * Button events for guitar controllers. Valid buttons are HOME and PLUS
   * for the StarPower/Home button and the + button. Furthermore, you get
   * FRET_FAR_UP, FRET_UP, FRET_MID, FRET_LOW, FRET_FAR_LOW for fret
   * activity and STRUM_BAR_UP and STRUM_BAR_LOW for the strum bar.
   * Payload type is struct xwii_event_key.
   */
  rb_define_const(mXWiimote_EventTypes, "GUITAR_KEY", INT2NUM(XWII_EVENT_GUITAR_KEY));

  /**
   * Document-const: XWiimote::EventTypes::GUITAR_MOVE
   *
   * Guitar movement event
   *
   * Movement information for guitar controllers. Payload is of type
   * struct xwii_event_abs. The first element contains X and Y direction
   * of the analog stick. The second element contains whammy-bar movement
   * information as x-value. The third element contains fret-bar absolute
   * positioning information as x-value.
   */
  rb_define_const(mXWiimote_EventTypes, "GUITAR_MOVE", INT2NUM(XWII_EVENT_GUITAR_MOVE));

  /**
   * Document-const: XWiimote::EventTypes::GONE
   *
   * Removal Event
   *
   * This event is sent whenever the device was removed. No payload is
   * provided. Non-hotplug aware applications may discard this event.
   *
   * This is only returned if you explicitly watched for hotplug events.
   * See xwii_iface_watch().
   */
  rb_define_const(mXWiimote_EventTypes, "GONE", INT2NUM(XWII_EVENT_GONE));

  /**
   * Document-const: XWiimote::EventTypes::NUM
   *
   * Number of available event types
   *
   * The value of this constant may increase on each new library revision.
   * It is not guaranteed to stay constant. However, it may never shrink.
   */
  rb_define_const(mXWiimote_EventTypes, "NUM", INT2NUM(XWII_EVENT_NUM));
}
