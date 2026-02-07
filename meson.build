project('hello-world-gtk', 'c',
  version: '0.0.1~proto',
  default_options: [
    'warning_level=3',
    'buildtype=debug',
  ],
)

dependencies = [ dependency('gtk4'), dependency('json-glib-1.0')]

# Define output directory
build_dir = meson.current_build_dir()
bin_dir = build_dir / 'build'

# Ensure bin/ exists
run_command('mkdir', '-p', bin_dir)

gnome = import('gnome')

# Compile GIO resources from XML
resources = gnome.compile_resources('myresources',
  'myresources.xml',
  c_name: 'myresources',
)

# Gather source files
src_files = [
  'src/main.c', 
]

src_files += files(
  'src/main.c',
  'src/window.c',
  'src/widgets/alert_dialog.c',
  'src/widgets/button.c',
  'src/app_data.c',
  'src/cli.c',
  'src/config.c',
  'src/locale.c',
  'src/utils.c',
  'src/window_callback.c',
  'src/window_init.c'
)

# Validate MetaInfo file
metainfo_file = '/pkg/flatpak/io.github.xgui4.hello_world_gtk.metainfo.xml'
ascli_exe = find_program('appstreamcli', required: false)
if ascli_exe.found()
  test('validate metainfo file',
        ascli_exe,
        args: ['validate',
               '--no-net',
               '--pedantic',
               metainfo_file]
  )
endif

executable('hello-world-gtk',
  src_files,
  resources,
  include_directories: include_directories('.'),
  dependencies: dependencies,
  build_by_default: true,
  install: true,
)