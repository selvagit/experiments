const soundEffects = {
    click: new Audio('assets/sounds/click.mp3'),
    error: new Audio('assets/sounds/error.mp3'),
};

let volume = 0.5;

function setVolume(newVolume) {
    volume = newVolume;
    soundEffects.click.volume = volume;
    soundEffects.error.volume = volume;
}

function playClickSound() {
    soundEffects.click.currentTime = 0; // Reset to start
    soundEffects.click.play();
}

function playErrorSound() {
    soundEffects.error.currentTime = 0; // Reset to start
    soundEffects.error.play();
}

document.addEventListener('DOMContentLoaded', () => {
    const volumeControl = document.getElementById('volume-control');
    if (volumeControl) {
        volumeControl.addEventListener('input', (event) => {
            setVolume(event.target.value);
        });
    });
});

export { playClickSound, playErrorSound, setVolume };