# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'xwiimote/version'

Gem::Specification.new do |spec|
  spec.name          = "xwiimote"
  spec.version       = Xwiimote::VERSION
  spec.authors       = ["Simon Kohlmeyer"]
  spec.email         = ["simon.kohlmeyer@gmail.com"]
  spec.description   = %q{Simple wrapper around the xwiimote library}
  spec.summary       = %q{Simple wrapper around the xwiimote library}
  spec.homepage      = ""
  spec.license       = "MIT"

  spec.files         = `git ls-files`.split($/)
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.extensions    = spec.files.grep(%r{^ext/.*\.so^})
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]

  spec.add_development_dependency "bundler", "~> 1.3"
  spec.add_development_dependency "rake"
  spec.add_development_dependency "rake-compiler"
end
