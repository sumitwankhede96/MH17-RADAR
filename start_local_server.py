#!/usr/bin/env python3
from http.server import ThreadingHTTPServer, SimpleHTTPRequestHandler
from pathlib import Path
import os
os.chdir(Path(__file__).resolve().parent)
print('MH17 RADAR test server: http://127.0.0.1:8000')
ThreadingHTTPServer(('127.0.0.1',8000),SimpleHTTPRequestHandler).serve_forever()
