project(
  'libdrv-st-otgfs',
  'c',
  meson_version : '>= 1.3.0',
  version : run_command('support/meson/version.sh', 'get-vcs', check: true).stdout().strip(),
  default_options: [
      'c_std=gnu11',
      'warning_level=3', 'optimization=s',
      'default_library=static', 'b_staticpic=false',
      'licensedir=share/info/libdrv-st-otgfs',
      'pkgconfig.relocatable=true',
      'config=configs/defconfig',
  ],
)

pkg = import('pkgconfig')
ssmod = import('sourceset')

kconfig_file = meson.current_source_dir() / 'Kconfig'
kconfig_proj = subproject('kconfig', default_options: ['kconfig=@0@'.format(kconfig_file)])
kconfig_h = kconfig_proj.get_variable('kconfig_h')
kconfig_data = kconfig_proj.get_variable('kconfig_data')

# drivers need merlin driver framework for dts and io accesses abstractions
merlin_proj = subproject('merlin')
merlin_dep = merlin_proj.get_variable('merlin_dep')

shield_dep = dependency('shield', required : true)

dependencies = []
sources = ssmod.source_set()

drv_inc = include_directories('include')

subdir('include')
subdir('src')

dependencies += [merlin_dep, shield_dep]

libdrv_st_otgfs = static_library(
  'drv-st-otgfs',
  sources_config,
  dependencies : dependencies,
  include_directories : drv_inc,
  install : true,
)
