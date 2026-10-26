from pathlib import Path

p = Path("index.html")
s = p.read_text()

# Remove the old demo button if present, then add a clean one.
s = s.replace(
    '<button id="demoBtn" onclick="alert(\'Demo Mode setup pending\')">Start Demo Mode</button>', ''
)
if 'id="demoBtn"' not in s:
    s = s.replace(
        '<button id="connect">Connect Arduino</button>',
        '<button id="connect">Connect Arduino</button><button id="demoBtn">Start Demo Mode</button>'
    )

demo = """
const demoBtn=document.querySelector('#demoBtn');
let demoTimer=null,demoAngle=0,demoOn=false;
demoBtn.onclick=()=>{
 if(demoOn){
  clearInterval(demoTimer);demoOn=false;detections.clear();ce.textContent='0';
  demoBtn.textContent='Start Demo Mode';cb.disabled=false;
  setStatus('Disconnected — connect Arduino USB');return;
 }
 demoOn=true;cb.disabled=true;demoBtn.textContent='Stop Demo Mode';
 setStatus('DEMO MODE — simulated data only',true);
 demoTimer=setInterval(()=>{
  demoAngle=(demoAngle+3)%181;angleNow=demoAngle;ae.textContent=demoAngle+'°';
  detections.clear();
  [{angle:45,distance:120},{angle:90,distance:250},{angle:135,distance:180}]
  .forEach(t=>{if(Math.abs(t.angle-demoAngle)<6)detections.set(String(t.angle),{...t,time:Date.now()})});
  ce.textContent=detections.size;
  de.textContent=detections.size?[...detections.values()][0].distance+' cm':'—';
 },80);
};
"""

# Remove any previous attempt's demo code, then insert exactly once.
start = "const demoBtn=document.querySelector('#demoBtn');"
while start in s:
    a = s.index(start)
    b = s.index("cb.onclick=connect;db.onclick=cleanup;", a)
    s = s[:a] + s[b:]

marker = "cb.onclick=connect;db.onclick=cleanup;"
if marker not in s:
    raise SystemExit("ERROR: Could not find JavaScript insertion point; file unchanged.")

s = s.replace(marker, demo + "\n" + marker, 1)

if 'id="demoBtn"' not in s or "demoBtn.onclick" not in s:
    raise SystemExit("ERROR: Demo Mode validation failed.")

p.write_text(s)
print("SUCCESS: Demo Mode button and animation added.")
