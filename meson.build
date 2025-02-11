project('colormap_shaders', 'cpp', version: '0.0')

qt6= import('qt6')

qt6_dep = dependency('qt6', modules: 'Core')

colormap_sources = qt6.compile_resources(sources:'shaders.qrc')

colormap_shaders_include_path = include_directories('include')

library('colormap_shaders', colormap_sources, dependencies: qt6_dep)
