#include "name.h"

#include <ruby.h>
#include "ruby-xwiimote.h"
#include <xwiimote.h>

/*
 * Document-module: XWiimote::Name
 *
 * Contains XWII_NAME_... constants
 */
void initialize_name() {
  VALUE mXWiimote_Name = rb_define_module_under(mXWiimote, "Name");

  /**
   * Document-const: XWiimote::Name::CORE
   *
   * Name of the core input device
   */
  rb_define_const(mXWiimote_Name, "CORE", rb_str_new2(XWII_NAME_CORE));

  /**
   * Document-const: XWiimote::Name::ACCEL
   *
   * Name of the accelerometer input device
   */
  rb_define_const(mXWiimote_Name, "ACCEL", rb_str_new2(XWII_NAME_ACCEL));

  /**
   * Document-const: XWiimote::Name::IR
   *
   * Name of the IR input device 
   */
  rb_define_const(mXWiimote_Name, "IR", rb_str_new2(XWII_NAME_IR));


  /**
   * Document-const: XWiimote::Name::MOTION_PLUS
   *
   * Name of the motion-plus input device 
   */
  rb_define_const(mXWiimote_Name, "MOTION_PLUS", rb_str_new2(XWII_NAME_MOTION_PLUS));

  /**
   * Document-const: XWiimote::Name::NUNCHUK
   *
   * Name of the nunchuk input device 
   */
  rb_define_const(mXWiimote_Name, "NUNCHUK", rb_str_new2(XWII_NAME_NUNCHUK));

  /**
   * Document-const: XWiimote::Name::CLASSIC_CONTROLLER
   *
   * Name of the classic-controller input device 
   */
  rb_define_const(mXWiimote_Name, "CLASSIC_CONTROLLER", rb_str_new2(XWII_NAME_CLASSIC_CONTROLLER));

  /**
   * Document-const: XWiimote::Name::BALANCE_BOARD
   *
   * Name of the balance-board input device 
   */
  rb_define_const(mXWiimote_Name, "BALANCE_BOARD", rb_str_new2(XWII_NAME_BALANCE_BOARD));

  /**
   * Document-const: XWiimote::Name::PRO_CONTROLLER
   *
   * Name of the pro-controller input device 
   */
  rb_define_const(mXWiimote_Name, "PRO_CONTROLLER", rb_str_new2(XWII_NAME_PRO_CONTROLLER));

  /**
   * Document-const: XWiimote::Name::DRUMS
   *
   * Name of the drums-controller input device 
   */
  rb_define_const(mXWiimote_Name, "DRUMS", rb_str_new2(XWII_NAME_DRUMS));

  /**
   * Document-const: XWiimote::Name::GUITAR
   *
   * Name of the guitar-controller input device 
   */
  rb_define_const(mXWiimote_Name, "GUITAR", rb_str_new2(XWII_NAME_GUITAR));
}
