install-venv:
	python3 -m venv venv

install-requirements:
	venv/bin/pip install -r requirements.txt

lab1:
	python -u lab1/main.py