window.onload = function() {
    const prev = document.getElementById('prev');
    const next = document.getElementById('next');
    const stage = document.getElementById('stage');
    const slides = document.querySelectorAll('.slide');
    const slideWidth = slides[0].clientWidth; // Get width of one slide
    let currentSlide = 0; // Current slide index

    function updateSlide() {
        stage.scrollTo({
            left: currentSlide * slideWidth,
            behavior: 'smooth'
        });
    }

    next.addEventListener('click', () => {
        currentSlide = (currentSlide + 1) % slides.length; // Loop back to 0 after last slide
        updateSlide();
    });

    prev.addEventListener('click', () => {
        currentSlide = (currentSlide - 1 + slides.length) % slides.length; // Loop to last slide from first
        updateSlide();
    });
};
