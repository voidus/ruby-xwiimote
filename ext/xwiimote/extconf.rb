require 'mkmf'

unless find_header('xwiimote.h')
  abort('Please install the xwiimote library.')
end

create_makefile 'xwiimote'
