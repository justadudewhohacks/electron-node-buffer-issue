const electron = require('electron');

const { app, BrowserWindow } = electron;

let win;
const createWindow = () => {
  win = new BrowserWindow();
  win.setResizable(true);
  win.loadURL('file://' + __dirname + '/index.html');
};

app.on('ready', createWindow);

app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') {
    app.quit();
  }
});

app.on('activate', () => {
  if (win === null) {
    createWindow();
  }
});
