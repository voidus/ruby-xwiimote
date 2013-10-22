#include "key.h"

#include <ruby.h>
#include <xwiimote.h>

#include "ruby-xwiimote.h"

/**
 * Document-module: XWiimote::Key
 *
 * Key Event Identifiers
 *
 * For each key found on a supported device, a separate key identifier is
 * defined. Note that a device may have a specific key (for instance: HOME) on
 * the main device and on an extension device. An application can detect which
 * key was pressed examining the event-type field.
 * Some devices report common keys as both, extension and core events. In this
 * case the kernel is required to filter these and you should report it as a
 * bug. A single physical key-press should never be reported twice, even on two
 * different interfaces.
 *
 * Most of the key-names should be self-explanatory.
 */
void initialize_key() {
  VALUE mXWiimote_Key = rb_define_module_under(mXWiimote, "Key");

  rb_define_const(mXWiimote_Key, "LEFT", INT2NUM(XWII_KEY_LEFT));
  rb_define_const(mXWiimote_Key, "RIGHT", INT2NUM(XWII_KEY_RIGHT));
  rb_define_const(mXWiimote_Key, "UP", INT2NUM(XWII_KEY_UP));
  rb_define_const(mXWiimote_Key, "DOWN", INT2NUM(XWII_KEY_DOWN));
  rb_define_const(mXWiimote_Key, "A", INT2NUM(XWII_KEY_A));
  rb_define_const(mXWiimote_Key, "B", INT2NUM(XWII_KEY_B));
  rb_define_const(mXWiimote_Key, "PLUS", INT2NUM(XWII_KEY_PLUS));
  rb_define_const(mXWiimote_Key, "MINUS", INT2NUM(XWII_KEY_MINUS));
  rb_define_const(mXWiimote_Key, "HOME", INT2NUM(XWII_KEY_HOME));
  rb_define_const(mXWiimote_Key, "ONE", INT2NUM(XWII_KEY_ONE));
  rb_define_const(mXWiimote_Key, "TWO", INT2NUM(XWII_KEY_TWO));
  rb_define_const(mXWiimote_Key, "X", INT2NUM(XWII_KEY_X));
  rb_define_const(mXWiimote_Key, "Y", INT2NUM(XWII_KEY_Y));
  rb_define_const(mXWiimote_Key, "TL", INT2NUM(XWII_KEY_TL));
  rb_define_const(mXWiimote_Key, "TR", INT2NUM(XWII_KEY_TR));
  rb_define_const(mXWiimote_Key, "ZL", INT2NUM(XWII_KEY_ZL));
  rb_define_const(mXWiimote_Key, "ZR", INT2NUM(XWII_KEY_ZR));

  /**
   * Document-const: XWiimote::Key::THUMBL
   *
   * Left thumb button
   *
   * This is reported if the left analog stick is pressed. Not all analog
   * sticks support this. The Wii-U Pro Controller is one of few devices
   * that report this event.
   */
  rb_define_const(mXWiimote_Key, "THUMBL", INT2NUM(XWII_KEY_THUMBL));

  /**
   * Document-const: XWiimote::Key::THUMBR
   *
   * Right thumb button
   *
   * This is reported if the right analog stick is pressed. Not all analog
   * sticks support this. The Wii-U Pro Controller is one of few devices
   * that report this event.
   */
  rb_define_const(mXWiimote_Key, "THUMBR", INT2NUM(XWII_KEY_THUMBR));

  /**
   * Document-const: XWiimote::Key::C
   *
   * Extra C button
   *
   * This button is not part of the standard action pad but reported by
   * extension controllers like the Nunchuk. It is supposed to extend the
   * standard A and B buttons.
   */
  rb_define_const(mXWiimote_Key, "C", INT2NUM(XWII_KEY_C));

  /**
   * Document-const: XWiimote::Key::Z
   *
   * Extra Z button
   *
   * This button is not part of the standard action pad but reported by
   * extension controllers like the Nunchuk. It is supposed to extend the
   * standard X and Y buttons.
   */
  rb_define_const(mXWiimote_Key, "Z", INT2NUM(XWII_KEY_Z));

  /**
   * Document-const: XWiimote::Key::STRUM_BAR_UP
   *
   * Guitar Strum-bar-up event
   *
   * Emitted by guitars if the strum-bar is moved up.
   */
  rb_define_const(mXWiimote_Key, "STRUM_BAR_UP", INT2NUM(XWII_KEY_STRUM_BAR_UP));

  /**
   * Document-const: XWiimote::Key::STRUM_BAR_DOWN
   *
   * Guitar Strum-bar-down event
   *
   * Emitted by guitars if the strum-bar is moved down.
   */
  rb_define_const(mXWiimote_Key, "STRUM_BAR_DOWN", INT2NUM(XWII_KEY_STRUM_BAR_DOWN));

  /**
   * Document-const: XWiimote::Key::FRET_FAR_UP
   *
   * Guitar Fret-Far-Up event
   *
   * Emitted by guitars if the upper-most fret-bar is pressed.
   */
  rb_define_const(mXWiimote_Key, "FRET_FAR_UP", INT2NUM(XWII_KEY_FRET_FAR_UP));

  /**
   * Document-const: XWiimote::Key::FRET_UP
   *
   * Guitar Fret-Up event
   *
   * Emitted by guitars if the second-upper fret-bar is pressed.
   */
  rb_define_const(mXWiimote_Key, "FRET_UP", INT2NUM(XWII_KEY_FRET_UP));

  /**
   * Document-const: XWiimote::Key::FRET_MID
   *
   * Guitar Fret-Mid event
   *
   * Emitted by guitars if the mid fret-bar is pressed.
   */
  rb_define_const(mXWiimote_Key, "FRET_MID", INT2NUM(XWII_KEY_FRET_MID));

  /**
   * Document-const: XWiimote::Key::FRET_LOW
   *
   * Guitar Fret-Low event
   *
   * Emitted by guitars if the second-lowest fret-bar is pressed.
   */
  rb_define_const(mXWiimote_Key, "FRET_LOW", INT2NUM(XWII_KEY_FRET_LOW));

  /**
   * Document-const: XWiimote::Key::FRET_FAR_LOW
   *
   * Guitar Fret-Far-Low event
   *
   * Emitted by guitars if the lower-most fret-bar is pressed.
   */
  rb_define_const(mXWiimote_Key, "FRET_FAR_LOW", INT2NUM(XWII_KEY_FRET_FAR_LOW));

  /**
   * Document-const: XWiimote::Key::NUM
   *
   * Number of key identifiers
   *
   * This defines the number of available key-identifiers. It is not
   * guaranteed to stay constant and may change when new identifiers are
   * added. However, it will never shrink.
   */
  rb_define_const(mXWiimote_Key, "NUM", INT2NUM(XWII_KEY_NUM));
}
