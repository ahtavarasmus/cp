from sys import argv
from time import sleep
from logging import basicConfig, INFO
from watchdog.observers import Observer 
from watchdog.events import LoggingEventHandler 

if __name__ == "__main__":
    basicConfig(level=INFO)
    path = argv[1] if len(argv) > 1 else '.'
    event_handler = LoggingEventHandler()
    observer = Observer()
    observer.schedule(event_handler,path,recursive=False)
    observer.start()
    observer.join()
