#include "ruby-xwiimote.h"

#include <xwiimote.h>
#include <ruby.h>

#include "event_types.h"
#include "name.h"
#include "key.h"

void Init_xwiimote() {
  mXWiimote = rb_define_module("XWiimote");

  initialize_event_types();
  initialize_name();
  initialize_key();
}
