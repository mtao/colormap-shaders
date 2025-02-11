import jinja2

from pathlib import Path

env = jinja2.Environment(loader=jinja2.FileSystemLoader("./"))
template = env.get_template("shaders.qrc.template")


my_path = Path(__file__)
base_path = my_path.parent
print(dir(base_path))
files = [x.name for x in (base_path / "shaders/glsl").iterdir()]

print(template.render(files=files))

