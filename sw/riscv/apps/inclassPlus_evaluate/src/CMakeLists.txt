

# Specify the include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

# Specify the source files
set(SRCS
    main.c
    cospi.c
    filter.c
    mod.c
    profile_Yuxuan_iteration.c
    repmat.c
    test_classifier.c
    aggregatePredict.c
    denoise_rwd.c
    find.c
    movmedian.c
    profile_Yuxuan_iteration_data.c
    rtGetInf.c
    unique.c
    bandpower.c
    diff.c
    findpeaks.c
    mrdivide_helper.c
    profile_Yuxuan_iteration_emxutil.c
    rtGetNaN.c
    updateCache.c
    eml_rand_mt19937ar.c
    abs.c
    ismember.c
    my_Extract_features_Jep.c
    profile_Yuxuan_iteration_initialize.c
    rt_nonfinite.c
    vvarstd.c
    colon.c
    eml_rand_mt19937ar_stateful.c
    Lorenz_features.c
    nonzeros.c
    profile_Yuxuan_iteration_rtwutil.c
    sinpi.c
    Yuxuan_iterative_test.c
    combineVectorElements.c
    eml_setop.c
    Lorenz_plot.c
    nullAssignment.c
    profile_Yuxuan_iteration_terminate.c
    sort.c
    CompactClassificationEnsemble.c
    features_Freq_calculator.c
    pan_tompkin_algorithm_segmented.c
    rand.c
    SortedBuffer.c
    CompactClassificationModel.c
    fft.c
    mean.c
    plomb.c
    randn.c
    sortIdx.c
    CompactClassificationTree.c
    FFTImplementationCallback.c
    minOrMax.c
    predictOneWithCache.c
    randperm.c
    strcmp.c
)

# Add an executable target
add_executable(InclassPlus ${SRCS})

# Link against the math library
target_link_libraries(InclassPlus m)
