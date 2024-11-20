from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler
import subprocess


class MyHandler(FileSystemEventHandler):
    @staticmethod
    def work(event) -> str | bool:
        if "output" in event.src_path:
            return False
        if not event.is_directory and event.src_path.endswith("pas"):
            return event.src_path
        elif not event.is_directory and event.src_path.endswith("txt"):
            return "\\".join(event.src_path.split('\\')[:-1] + [event.src_path.split('\\')[-1].split('_')[0] + "_.pas"])
        return False

    def on_modified(self, event):
        try:
            path = self.work(event)
            if path:
                name = event.src_path.split('\\')[-1].split('_')[0]
                out = "\\".join(event.src_path.split('\\')[:-1] + [event.src_path.split('\\')[-1].split('_')[0] + "_output.txt"])
                inp = "\\".join(event.src_path.split('\\')[:-1] + [event.src_path.split('\\')[-1].split('_')[0] + "_input.txt"])
                print(rf'"C:\Program Files (x86)\PascalABC.NET\pabcnetc.exe" "{inp}" "{out}"')
                print(rf'"{path[:-3]}exe" "{inp}" "{out}"')
                subprocess.call(rf'"C:\Program Files (x86)\PascalABC.NET\pabcnetc.exe" "{path}"')
                print("compiled")
                out_prg = subprocess.getoutput(rf'"{path[:-3]}exe" "{inp}" "{out}"')
                print("run", out_prg, sep='\n')
        except Exception as ex:
            print("\n\n\n\n\n", ex)

    def on_deleted(self, event):
        if self.work(event):
            print(f"Событие {event.event_type} по пути {event.src_path}")


handler = MyHandler()
observer = Observer()
path = __file__[:-10] + "prj"
observer.schedule(handler, path=path, recursive=True)
observer.start()
try:
    while observer.is_alive():
        observer.join(1)
finally:
    observer.stop()
    observer.join()
